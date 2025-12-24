#include <bits/stdc++.h>
using namespace std;

#define task "510"
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
const ll MOD = 1e9 + 7;

ll n, dp[N], a[N], c[N], len;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    string s = to_string(n);
    len = s.length();
    for (int i = 0; i < len; i++){
        a[i + 1] = s[i] - '0';
    }
    for (int sum = 0; sum <= 18; ++sum){
        for (int i = 0; i <= 9; i++){
            int j = sum - i;
            if (0 <= j && j <= 9){
                c[sum]++;
            }
        }
    }
}

void solve(){
    cin >> n;
    init();
    dp[0] = 1;
    for (int i = 1; i <= len; i++){
        dp[i] += dp[i - 1] * c[a[i]];
        if (i > 1 && a[i - 1]) dp[i] += dp[i - 2] * c[a[i - 1] * 10 + a[i]];
    }
    cout << dp[len] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
