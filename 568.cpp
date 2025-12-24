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

string s;
int dp[M][M];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[1][n] << el;
}


int main() {
    tassk();
    solve();
    return 0;
}
