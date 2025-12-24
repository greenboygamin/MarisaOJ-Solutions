#include <bits/stdc++.h>
using namespace std;

#define task "341"
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
const ll M = 5e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e7 + 1203;

ll n, a[N], b[N], c[N], dp[M][M];

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
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll maxs = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i == 1 || j == 1) dp[i][j] = a[i] * b[j];
            else dp[i][j] = max(dp[i - 1][j - 1], (ll)0) + a[i] * b[j];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) maxs = max(dp[i][j], maxs);
    }
    cout << maxs;
}

int main() {
    tassk();
    solve();
    return 0;
}
