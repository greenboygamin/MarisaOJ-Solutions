#include <bits/stdc++.h>
using namespace std;

#define task "571"
#define el "\n"
typedef long long int ll;
const int MOD = 1e9 + 7;

int n, m, k;
string a, b;
int dp[2][205][205];
int extArr[2][205][205];

void solve() {
    cin >> n >> m >> k >> a >> b;
    a = " " + a;
    b = " " + b;

    memset(dp, 0, sizeof dp);
    memset(extArr, 0, sizeof extArr);
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int cur = i & 1, prv = cur ^ 1;
        for (int j = 0; j <= m; j++) {
            for (int t = 0; t <= k; t++) {
                dp[cur][j][t] = 0;
                extArr[cur][j][t] = 0;
            }
        }

        for (int t = 0; t <= k; t++) {
            dp[cur][0][t] = dp[prv][0][t];
        }

        for (int j = 1; j <= m; j++) {
            dp[cur][j][0] = dp[prv][j][0];
            for (int t = 1; t <= k; t++) {
                if (a[i] == b[j]) {
                    extArr[cur][j][t] = (extArr[prv][j-1][t] + dp[prv][j-1][t-1]) % MOD;
                } else {
                    extArr[cur][j][t] = 0;
                }
                dp[cur][j][t] = (dp[prv][j][t] + extArr[cur][j][t]) % MOD;
            }
        }
    }

    cout << dp[n & 1][m][k] << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();
    return 0;
}
