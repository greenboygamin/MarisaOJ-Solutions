#include <bits/stdc++.h>
using namespace std;

#define task "575"
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

ll n, k, dp[N], c[N];
vll cu[N];

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
    cin >> n;
    ll maxs = INT_MIN;
    for (int i = 1; i <= n; i++){
        ll l, r;
        cin >> l >> r;
        cu[r].pb(l);
        maxs = max(maxs, r);
    }
    for (int i = 1; i <= maxs; i++){
        dp[i] = dp[i - 1];
        for (auto j : cu[i]){
            dp[i] = max(dp[i], dp[j - 1] + i - j + 1);
        }
    }
    cout << dp[maxs];
}

int main() {
    tassk();
    solve();
    return 0;
}
