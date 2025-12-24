#include <bits/stdc++.h>
using namespace std;

#define task "NGOAC"
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
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 17;
const ll M = 2005;
const ll B = 131;
const ll INF = 1e18;
const ll MOD = 123456789;
const ll OFFSET = 500000;

int n, a[505], b[505];
ll dp[4 * N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void Solve() {
    cin >> n;
    fill(dp, dp + 4 * N, -INF);
    dp[OFFSET] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= n; i++){
        vpll tmp;
        for (int j = 0; j < N; j++){
            if (0 <= j - a[i] && dp[j - a[i]] != -INF){
                tmp.pb({j, dp[j - a[i]] + a[i] + b[i]});
            }
        }
        for (auto x : tmp){
            ll pos = x.first, val = x.second;
            dp[pos] = max(dp[pos], val);
        }
    }
    ll maxs = -INF;
    for (int i = OFFSET; i < N; i++){
        if (dp[i] > i - OFFSET) maxs = max(dp[i], maxs);
    }
    cout << maxs;
}

int main() {
    Task();
    Solve();
    return 0;
}
