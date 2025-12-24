#include <bits/stdc++.h>
using namespace std;

#define task "326"
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

int n;
vector<int> adj[N];
int d[N];
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
    d[u] = 1;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
            d[u] += d[v];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);

    for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

int main() {
    tassk();
    solve(); 
    return 0;
}