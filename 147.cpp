#include <bits/stdc++.h>
using namespace std;

#define task "147"
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
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e7 + 1203;
ll n, k, a[N], dp[2][5 * M][2];

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
    //dp[i][j][state] : xet den vi tri i, xoa toi da j lan, state = 1: xoa, state = 0: k xoa thg o i
    for (int i = 1; i <= n; i++){
        if (i & 1){
            dp[1][0][0] = dp[0][0][0] + a[i];
            dp[1][0][1] = dp[0][0][1] + a[i];
            for (int j = 1; j <= k; j++){
                dp[1][j][0] = max(dp[0][j][0] + a[i], dp[0][j][1] + a[i]);
                dp[1][j][1] = max(dp[0][j - 1][0], dp[0][j][1]);
            }
        }
        else {
            dp[0][0][0] = dp[1][0][0] + a[i];
            dp[0][0][1] = dp[1][0][1] + a[i];
            for (int j = 1; j <= k; j++){
                dp[0][j][0] = max(dp[1][j][0] + a[i], dp[1][j][1] + a[i]);
                dp[0][j][1] = max(dp[1][j - 1][0], dp[1][j][1]);
            }
        }
    }
    ll maxs = -9e18;
    int i = n % 2;
    for (int j = 0; j <= k; j++){
        maxs = max({maxs, dp[i][j][0], dp[i][j][1]});
    }
    cout << maxs;
}


int main() {
    tassk();
    solve();
    return 0;
}
