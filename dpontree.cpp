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
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e9 + 7;

ll n, k, a[N];
vector<int> adj[N];
ll dp[N][4], dp2[4];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs(int u, int p){
    dp[u][0] = dp[u][3] = 0;
    dp[u][1] = a[u]; dp[u][2] = -a[u];
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < 4; i++) dp2[i] = -INF;
        dp2[0] = max(dp2[0], dp[u][0] + dp[v][3]);
        dp2[1] = max({dp2[1], dp[u][1] + dp[v][3], dp[u][0] + dp[v][1]});
        dp2[2] = max({dp2[2], dp[u][2] + dp[v][3], dp[u][0] + dp[v][2]});
        dp2[3] = max({dp2[3], dp[u][1] + dp[v][2], dp[u][2] + dp[v][1], dp[u][0] + dp[v][3], dp[u][3] + dp[v][3]});
        for (int i = 0; i < 4; i++) dp[u][i] = dp2[i];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(1, -1);
    cout << dp[1][3] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}