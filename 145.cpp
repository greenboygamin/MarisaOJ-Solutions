#include <bits/stdc++.h>
using namespace std;

#define task "145"
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

int n, m, a[N], dp[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n >> m;
    int mins = INT_MAX;
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int x = a[j];
            if (i >= x && !dp[i - x]){
                //cout << x << el;
                dp[i] = 1;
                break;
                
            }
        }
    }
    if (dp[n]) cout << "Marisa"; else cout << "Reimu";
}

int main() {
    tassk();
    solve();
    return 0;
}
