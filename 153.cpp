#include <bits/stdc++.h>
using namespace std;

#define task "153"
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

string s;
int t, dp[3 * M][3 * M];

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
    int l, r;
    cin >> l >> r;
    if (dp[l - 1][r - 1]) cout << "YES" << el;
    else cout << "NO" << el;
}

int main() {
    tassk();
    cin >> s;
    string ss = s;
    reverse(ss.begin(), ss.end());
    int n = s.length();
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) dp[i][i + 1] = (s[i] == s[i + 1]);
    for (int len = 2; len < n; len++){
        for (int i = 0; i + len < n; i++){
            int j = i + len;
            dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }
    }
    cin >> t; while (t--)
    solve();
    return 0;
}
