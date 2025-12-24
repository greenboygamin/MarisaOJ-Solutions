#include <bits/stdc++.h>
using namespace std;

#define task "155"
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

int n, m, q;
vector<int> adj[N];
int U[N], V[N], d[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs(){
    int d0 = INT_MAX;
    queue<int> q;
    for (int u = 1; u <= n; u++){
        if (U[u] == 0){
            d[u] = 0;
            q.push(u);
        }
        else d[u] = INT_MAX;
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (d[u] < d0){
            for (auto v : adj[u]){
                if (V[v] == 0){
                    d0 = d[u] + 1;
                }
                else if (d[V[v]] == INT_MAX){
                    d[V[v]] = d[u] + 1;
                    q.push(V[v]);
                }
            }
        }
    }
    return d0 != INT_MAX;
}

bool dfs(int u){
    for (int v : adj[u]){
        if (V[v] == 0 || (d[V[v]] == d[u] + 1 && dfs(V[v]))){
            V[v] = u;
            U[u] = v;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }
    int res = 0;
    while (bfs()){
        for (int u = 1; u <= n; u++){
            if (U[u] == 0 && dfs(u)){
                res++;
            }
        }
    }
    cout << res;
}


int main() {
    tassk();
    solve();
    return 0;
}