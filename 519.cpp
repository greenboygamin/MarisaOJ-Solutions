#include <bits/stdc++.h>
using namespace std;

#define task "519"
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

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    ll ans = 0;
    ll q; cin >> q;
    while (q--){
        int type, k;
        cin >> type >> k;
        if (type == 1) ans |= (1LL << k);
        if (type == 2) ans &= (~(1LL << k));
        if (type == 3) ans ^= (1LL << k);
        cout << ans << el;
    }
    
}

int main() {
    tassk();
    solve();
    return 0;
}