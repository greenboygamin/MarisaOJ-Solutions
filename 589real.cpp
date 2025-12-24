#include <bits/stdc++.h>
using namespace std;

#define task "589"
#define el "\n"
typedef long long ll;
const ll N = 500000;
const ll INF = 0x3f3f3f3f3f3f;
const ll OFFSET = 500000;
const ll SIZE = OFFSET * 2 + 1;

ll n, a[N], b[N];
ll dp[SIZE], tmp[SIZE];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < SIZE; i++) dp[i] = -INF;
    dp[OFFSET] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < SIZE; j++) tmp[j] = dp[j]; // Copy dp -> tmp

        if (a[i] >= 0) {
            for (int j = -N; j <= N; j++) {
                int from = j - a[i];
                if (from < -N || from > N) continue;
                ll val = dp[from + OFFSET] + a[i] + b[i];
                tmp[j + OFFSET] = max(tmp[j + OFFSET], val);
            }
        } else {
            for (int j = N; j >= -N; j--) {
                int from = j - a[i];
                if (from < -N || from > N) continue;
                ll val = dp[from + OFFSET] + a[i] + b[i];
                tmp[j + OFFSET] = max(tmp[j + OFFSET], val);
            }
        }

        for (int j = 0; j < SIZE; j++) dp[j] = tmp[j]; // Update dp
    }

    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        if (dp[i + OFFSET] >= i) ans = max(ans, dp[i + OFFSET]);
    }
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
