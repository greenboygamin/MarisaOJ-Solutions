#include <bits/stdc++.h>
using namespace std;

#define task "anarhie"
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
ll sz[M];
ll dp[M][M][2][2]; // dp[node][size][min_taken][max_taken]
ll dp2[M][2][2];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".in", "r")) {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs(int u, int p){
    dp[u][1][0][0] = 0;
    dp[u][1][0][1] = a[u];
    dp[u][1][1][0] = -a[u];
    dp[u][1][1][1] = 0;
    sz[u] = 1;
    for (int v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        for (int i = 1; i <= sz[u] + sz[v]; i++){
            for (int h2 = 0; h2 < 2; h2++){
                for (int h3 = 0; h3 < 2; h3++){
                    dp2[i][h2][h3] = -INF;
                }
            }
        }
        for (int i = 1; i <= sz[u]; i++){
            for (int j = 1; j <= sz[v]; j++){
                for (int h2 = 0; h2 < 2; h2++){ 
                    for (int h3 = 0; h3 < 2; h3++){
                        for (int h4 = 0; h4 < 2; h4++){
                            for (int h5 = 0; h5 < 2; h5++){
                                //cat / khong merge
                                if (h4 == 1 && h5 == 1){
                                    dp2[i + j][h2][h3] = max(dp2[i + j][h2][h3], dp[u][i][h2][h3] + dp[v][j][h4][h5]);
                                }
                                //khong cat / merge
                                if ((h2 & h4) == 0 && (h3 & h5) == 0){
                                    dp2[i + j - 1][h2 | h4][h3 | h5] = max(dp2[i + j - 1][h2 | h4][h3 | h5], dp[u][i][h2][h3] + dp[v][j][h4][h5]); 
                                }
                            }
                        }
                    }
                }
            }
        }
        sz[u] += sz[v];
        for (int i = 1; i <= sz[u]; i++){
            dp[u][i][0][0] = dp2[i][0][0];
            dp[u][i][1][0] = dp2[i][1][0];
            dp[u][i][0][1] = dp2[i][0][1];
            dp[u][i][1][1] = dp2[i][1][1];

        }
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
    for (int i = 1; i <= n; i++){
        cout << dp[1][i][1][1] << " ";
    }
}

int main() {
    tassk();
    solve();
    return 0;
}