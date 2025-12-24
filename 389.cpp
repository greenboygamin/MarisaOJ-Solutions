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

int n, a[505];
ll dp[M][M], b[M][M];

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
    for (int i = 1; i <= n; i++) cin >> a[i], b[i][i] = a[i], dp[i][i] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i + 1]){
            b[i][i + 1] = a[i] + 1;
            dp[i][i + 1] = 1;
        }
        else dp[i][i + 1] = 2;
    }  
    for (int len = 3; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            dp[i][j] = len;
            for (int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if (b[i][k] && b[i][k] == b[k + 1][j]){
                    dp[i][j] = 1;
                    b[i][j] = b[i][k] + 1;
                    break;
                }
            }
        }
    }
    cout << dp[1][n];
}

int main() {
    Task();
    Solve();
    return 0;
}
