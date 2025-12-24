#include <bits/stdc++.h>
using namespace std;

#define task "152"
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

string s; ll dp[M][M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll add(ll x, ll y){
    return (x % MOD + y % MOD) % MOD;
}

void solve(){
    cin >> s;
    int n = s.length();
    s = " " + s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (s[i] == '(' || s[i] == '?'){
                dp[i][j] = add(dp[i][j], dp[i - 1][j - 1]);
            }
            if (s[i] == ')' || s[i] == '?'){
                dp[i][j] = add(dp[i][j], dp[i - 1][j + 1]);
            }
        }
    }
    cout << dp[n][0] << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
