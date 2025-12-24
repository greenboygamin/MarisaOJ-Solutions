#include <bits/stdc++.h>
using namespace std;

#define task "493"
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

struct item{
    int w, v;
};

int n, s, dp[N];
vector<item> items;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        int w, v, a;
        cin >> w >> v >> a;
        int k = 1;
        while (a > 0){
            int cnt = min(a, k);
            items.pb({w * cnt, v * cnt});
            k <<= 1;
            a -= cnt;
        }
    }
    for (auto &it : items){
        for (int j = s; j >= it.w; j--){
            dp[j] = max(dp[j], dp[j - it.w] + it.v);
        }
    }
    cout << dp[s] << el;
}


int main() {
    tassk();
    solve();
    return 0;
}