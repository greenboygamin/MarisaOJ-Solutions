#include <bits/stdc++.h>
using namespace std;

#define task "576"
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
ll n;
unordered_map<ll, ll> dp;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

ll getmax(ll x){
    if (x < 12) return x;
    if (dp.count(x)) return dp[x];
    dp[x] = max(x, getmax(x / 2) + getmax(x / 3) + getmax(x / 4));
    return dp[x];
}

void solve(){
    cin >> n;
    cout << getmax(n) << el;
}


int main() {
    tassk(); int t; cin >> t; while (t--)
    solve();
    return 0;
}
