#include <bits/stdc++.h>
using namespace std;

#define task "230"
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

ll n, dp[N], a[N];
vector<int> adj[N];
ll maxs = INT_MIN;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void proc(ll &max1, ll &max2, ll cur){
    if (cur >= max2){
        max1 = max2; max2 = cur;
    }
    else max1 = max(max1, cur);
}

ll add(ll x, ll y){
    x += y;
    if (x >= MOD) x -= MOD;
    if (x < 0) x += MOD;
    return x;
}

ll mul(ll x, ll y){
    return (x % MOD * y % MOD) % MOD;
}

void dfs(int u, int p){
    dp[u] = a[u];
    ll max1 = 0, max2 = 0;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + a[u]);
        proc(max1, max2, dp[v]);
    }
    maxs = max(maxs, dp[u]);
    maxs = max(maxs, max1 + max2 + a[u]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, -1);
    cout << maxs << el;
}

int main() {
    tassk();
    solve();
    return 0;
}