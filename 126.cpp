#include <bits/stdc++.h>
using namespace std;

#define task "437"
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

int n, m;
vector<int> adj[N];
bool visited[N];

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
    for (auto v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if (m != n - 1){
        cout << "NO";
        return;
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    tassk();
    solve(); 
    return 0;
}