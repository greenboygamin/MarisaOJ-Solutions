#include <bits/stdc++.h>
using namespace std;

#define task "hopcroftkarp"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 17;
const ll M = 2e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

ll n, m, s, t, c[M][M], f[M][M], level[N];
int it[N];
vector<int> adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs(){
    fill(level, level + N, -1);
    level[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (level[v] == -1 && c[u][v] > f[u][v]){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return (level[t] != -1);
}

ll dfs(int u, ll flow){
    if (u == t) return flow;
    for (int &i = it[u]; i < adj[u].size(); i++){
        int v = adj[u][i];
        if (c[u][v] > f[u][v] && level[v] == level[u] + 1){
            ll delta = dfs(v, min(flow, c[u][v] - f[u][v]));
            if (delta > 0){
                f[u][v] += delta; f[v][u] -= delta;
                return delta;
            }
        }
    }    
    return 0;
}

int dinic(){
    ll res = 0;
    while (bfs()){
        fill(it, it + N, 0);
        while (ll flow = dfs(s, INF)){
            res += flow;
        }
    }
    return res;
}

void solve(){
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(v); adj[v].pb(u);
        c[u][v] += w;
    }
    cout << dinic();
}


int main() {
    tassk();
    solve();
    return 0;
}