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

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int cnt(ll x){
    int dem = 0;
    while (x){
        dem++;
        x &= x - 1;
    }
    return dem;
}

int pos(ll x){
    for (int i = 29; i >= 0; i--){
        if ((x >> i) & 1) return i;
    }
}

void solve() {
    ll a = 0;
    ll q; cin >> q;
    while (q--){
        int type; cin >> type;
        if (type == 1){
            int x;
            cin >> x;
            a ^= x;
        }
        if (type == 2){
            if (a == 0) continue;
            a &= ~(1 << pos(a));
        }
        if (type == 3){
            cout << cnt(a) << el;
        }
    }    
}

int main() {
    tassk();
    solve();
    return 0;
}