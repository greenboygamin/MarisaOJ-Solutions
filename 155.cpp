#include <bits/stdc++.h>
using namespace std;

#define task "155"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 17;
const ll M = 2e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

ll n, dp[M][M], a[N], k;
ll last[N], pre[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        dp[i][0] = 1;
        for (int j = 1; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            int p = pre[i];
            if (p > 0){
                dp[i][j] = (dp[i][j] - dp[p - 1][j - 1] + MOD) % MOD;
            }
        }
    }
    cout << dp[n][k] << el;
}


int main() {
    tassk();
    solve();
    return 0;
}