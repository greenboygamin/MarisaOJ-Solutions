#include <bits/stdc++.h>
using namespace std;

#define task "159"
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
const ll N = 4e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

ll n, k, a[N];
ll dp[M][M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
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

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - 1], a[i]));
        }
    }
    cout << dp[n][k];
}

int main() {
    tassk();
    solve();
    return 0;
}
