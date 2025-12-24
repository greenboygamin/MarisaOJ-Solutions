#include <bits/stdc++.h>
using namespace std;

#define task "195"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e5 + 5;
const ll M = 2e3 + 5;
const ll INF = 4e9;
const ll MOD = 1e8;

int up[20][N], d[N], n, q;
vector<int> adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs(int u, int p){
    up[0][u] = p;
    for (int i = 1; i < 20; i++) up[i][u] = up[i - 1][up[i - 1][u]];
    for (int v : adj[u]){
        if (v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v){
    if (d[u] < d[v]) swap(u, v);
    for (int i = 19; i >= 0; i--){
        if (d[u] - (1 << i) >= d[v]) u = up[i][u]; 
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--){
        if (up[i][u] != up[i][v]){
            u = up[i][u]; v = up[i][v];
        }
    }
    return up[0][u];
}

int find_k(int u, int k){
    for (int j = 0; (1 << j) <= k; j++){
        if (k >> j & 1) u = up[j][u];
    }
    return u;
}

int query(int u, int v, int w){
    int uv = lca(u, v);
    int dist1 = abs(d[u] - d[uv]);
    int dist2 = abs(d[v] - d[uv]);
    if (dist1 == w) return uv;
    else if (dist1 > w){
        return find_k(u, w);
    }
    else {
        return find_k(v, dist2 - (w - dist1));
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= q; i++){
        int u, v, w; cin >> u >> v >> w;
        cout << query(u, v, w) << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
