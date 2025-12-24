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
    ll q; cin >> q;
    while (q--){
        ll c = 0;
        ll a, b;
        cin >> a >> b;
        for (int i = 0; i < 15; i++){
            if (0 <= i && i <= 4) c |= ((BIT(a, i) ^ BIT(b, i)) << i);
            if (5 <= i && i <= 9) c |= ((BIT(a, i) & BIT(b, i)) << i);
            if (10 <= i && i <= 14) c |= ((BIT(a, i) | BIT(b, i)) << i);
        }
        cout << c << el;
    }
    
}

int main() {
    tassk();
    solve();
    return 0;
}