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

ll n, dp[100005][105], k;
vector<int> adj[N];
ll ans = 0;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs(int u, int p){
    dp[u][0] = 1;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        for (int d1 = 0; d1 < k; d1++){
            int d2 = k - d1 - 1;
            ans += dp[u][d1] * dp[v][d2];
        }
        for (int d = 1; d <= k; d++){
            dp[u][d] += dp[v][d - 1];
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, -1);
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}