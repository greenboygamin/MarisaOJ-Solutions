#include <bits/stdc++.h>
using namespace std;

#define task "572"
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

int n, t[N], r[N], dp[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i];
    for (int i = 1; i < n; i++) cin >> r[i];
    dp[1] = t[1]; dp[2] = min(t[1] + t[2], r[1]);
    for (int i = 3; i <= n; i++){
        dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
    }
    cout << dp[n];
}

int main() {
    tassk();
    solve();
    return 0;
}
