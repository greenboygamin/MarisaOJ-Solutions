#include <bits/stdc++.h>
using namespace std;

#define task "127"
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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n, q, h[N], par[N], a[N];
bool visited[N];
vector<int> adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void dfs(int u){
    visited[u] = 1;
    for (int v : adj[u]){
        if (!visited[v]){
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    while (q--){
        int u, v, val;
        cin >> u >> v >> val;
        vector<int> nodes;
        while (h[v] > h[u]){
            if (a[v] == 0) a[v] = val;
            nodes.pb(v);
            v = par[v];
        }
        if (a[u] == 0) a[u] = val;
        for (int x : nodes) par[x] = par[u];
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
}

int main() {
    tassk();
    solve(); 
    return 0;
}