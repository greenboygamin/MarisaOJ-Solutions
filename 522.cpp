#include <bits/stdc++.h>
using namespace std;

#define task "525"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e6;

int n, a[N];
unordered_map<ll, ll> cnt;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] ^= i;
        cnt[a[i]]++;
    }
    ll ans = 0;
    for (auto x : cnt){
        ll val = x.second;
        if (val) ans += (val * (val - 1)) / 2;
    }
    cout << ans;
}

int main() {
    tassk();
    solve();
    return 0;
}