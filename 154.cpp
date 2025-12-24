#include <bits/stdc++.h>
using namespace std;

#define task "154"
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
const ll MOD = 123456789;

ll n, dp[N], a[N];
unordered_map<ll, ll> last;

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
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        ll add = (dp[i - 1] * 2) % MOD;
        ll x = a[i];
        if (last.count(x)){
            int k = last[x];
            add = (add + MOD - dp[k - 1]) % MOD;
        }
        last[x] = i;
        dp[i] = add;
    }
    cout << dp[n] - 1 << el;
    //for (int i = 1; i <= n; i++) cout << dp[i] << " ";
}


int main() {
    tassk();
    solve();
    return 0;
}