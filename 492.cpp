#include <bits/stdc++.h>
using namespace std;

#define task ""
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

string s; 
int dp[M][M];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

bool check(char a, char b){
    return ((a == '(' && b == ')') || (a == '[' && b == ']'));
}

void Solve() {
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int len = 2; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){ 
            int j = i + len - 1;
            dp[i][j] = len;
            if (check(s[i], s[j])) dp[i][j] = (len == 2) ? 0 : dp[i + 1][j - 1];
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][k] + dp[k + 1][j], dp[i][j]);
            }
        } 
    }
    cout << dp[1][n] << el;
}

int main() {
    Task();
    Solve();
    return 0;
}
