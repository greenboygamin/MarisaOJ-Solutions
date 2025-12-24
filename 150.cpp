#include <bits/stdc++.h>
using namespace std;

#define task "150"
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

int a, b, dp[M][M];

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
    cin >> a >> b;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= a; i++){
        for (int j = 1; j <= b; j++){
            if (i == j) dp[i][j] = 0;
            else {
                for (int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                for (int k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
        }
    }
    cout << dp[a][b] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
