#include <bits/stdc++.h>
using namespace std;

#define task "349"
#define el "\n"
typedef long long ll;

struct Edge {
    int to;
    int cap;
    int rev; 
};

int n, m, q;
int s, t;
vector<vector<Edge>> g;
vector<int> level, it;
vector<int> doll, job;

void addEdge(int u, int v, int cap){
    int rev = g[v].size();
    g[u].push_back({v, cap, rev});
    g[v].push_back({u, 0, rev});
}

bool bfs(){
    fill(level.begin(), level.end(), -1);
    queue<int> qu;
    level[s] = 0; qu.push(s);
    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        for(auto &e : g[u]){
            if(level[e.to] == -1 && e.cap > 0){
                level[e.to] = level[u] + 1;
                qu.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int u, int pushed){
    if(u == t || pushed == 0) return pushed;
    for(int &i = it[u]; i < (int)g[u].size(); ++i){
        Edge &e = g[u][i];
        if(e.cap > 0 && level[e.to] == level[u] + 1){
            int got = dfs(e.to, min(pushed, e.cap));
            if(got > 0){
                e.cap -= got;
                g[e.to][e.rev].cap += got;
                return got;
            }
        }
    }
    return 0;
}

int dinic(){
    int flow = 0;
    while(bfs()){
        fill(it.begin(), it.end(), 0);
        while(int pushed = dfs(s, INT_MAX)){
            flow += pushed;
        }
    }
    return flow;
}

void build_graph(int T){
    int nodes = n + m + 2;
    s = 0; t = n + m + 1;
    g.assign(nodes, {});
    level.assign(nodes, -1);
    it.assign(nodes, 0);
    for(int i = 1; i <= n; ++i) addEdge(s, i, T);
    for(int k = 1; k <= q; ++k){
        int i = doll[k];
        int j = job[k];
        addEdge(i, j + n, 1);
    }
    for(int j = 1; j <= m; ++j) addEdge(j + n, t, 1);
}

void solve(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n >> m >> q;
    doll.assign(q + 1, 0);
    job.assign(q + 1, 0);
    for(int i = 1; i <= q; ++i){
        cin >> doll[i] >> job[i];
    }

    int L = 1, R = m, ans = -1;
    while(L <= R){
        int mid = (L + R) / 2;
        build_graph(mid);
        int flow = dinic();
        if(flow >= m){
            ans = mid;
            R = mid - 1;
        } else L = mid + 1;
    }
    cout << ans << el;
}

int main(){
    solve();
    return 0;
}
