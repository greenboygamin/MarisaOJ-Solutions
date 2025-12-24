#include <bits/stdc++.h>
using namespace std;

#define task "anarhie"
#define el "\n"
#define pb push_back
typedef long long int ll;
typedef vector<long long> vll;
const int N = 2005;
const ll INF = 2e9;

int n;
int v[N];
vector<int> adj[N];
int sz[N];
int dp[N][N][2][2];   // dp[node][size][min_taken][max_taken]
int dp2[N][2][2];

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
    dp[u][1][0][1] = v[u];
    dp[u][1][1][0] = -v[u];
    dp[u][1][1][1] = 0;
    sz[u] = 1;

    for (int to : adj[u]){
        if (to == p) continue;
        dfs(to, u);

        for (int i = 1; i <= sz[u] + sz[to]; i++)
            for (int h2 = 0; h2 < 2; h2++)
                for (int h3 = 0; h3 < 2; h3++)
                    dp2[i][h2][h3] = -INF;

        for (int i = 1; i <= sz[u]; i++)
            for (int j = 1; j <= sz[to]; j++)
                for (int h2 = 0; h2 < 2; h2++)
                    for (int h3 = 0; h3 < 2; h3++)
                        for (int h4 = 0; h4 < 2; h4++)
                            for (int h5 = 0; h5 < 2; h5++){
                                if (h4 == 1 && h5 == 1)
                                    dp2[i + j][h2][h3] = max(dp2[i + j][h2][h3], dp[u][i][h2][h3] + dp[to][j][h4][h5]);
                                if ((h2 & h4) == 0 && (h3 & h5) == 0)
                                    dp2[i + j - 1][h2 | h4][h3 | h5] = max(dp2[i + j - 1][h2 | h4][h3 | h5], dp[u][i][h2][h3] + dp[to][j][h4][h5]);
                            }

        sz[u] += sz[to];
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
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++){
        int x, y; cin >> x >> y;
        adj[x].pb(y); adj[y].pb(x);
    }

    dfs(1, 0);
    
    for (int i = 1; i <= n; i++) cout << dp[1][i][1][1] << " ";
    cout << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
