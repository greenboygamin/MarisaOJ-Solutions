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

int n, a[M][M], dp[55][55][55];

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
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    dp[1][1][1] = a[1][1];
    for (int t = 2; t <= 2 * n; t++){
        for (int i = 1; i <= n; i++){
            for (int k = 1; k <= n; k++){
                int j = t - i, l = t - k;
                if (j < 1 || n < j || l < 1 || n < l) continue;
                dp[i][j][k] = max({dp[i - 1][j][k - 1], dp[i - 1][j][k], dp[i][j - 1][k - 1], dp[i][j - 1][k]}) + a[i][j];
                if (i != k && j != l) dp[i][j][k] += a[k][l];
            }
        }
    }
    cout << dp[n][n][n];
}

int main() {
    Task();
    Solve();
    return 0;
}
    