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
const ll SIZE = MASK(26) - 1;

int n, a[26], f[SIZE];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

int pos(ll x){
    for (int i = 0; i < 26; i++){
        if (BIT(x, i)) return i;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        a[i] = 0;
        for (char c : s){
            a[i] |= (1 << (c - 'a'));
        }
    }
    int res = 0;
    for (int mask = 1; mask <= MASK(n) - 1; mask++){
        int id = pos(mask);
        f[mask] = (a[id] | f[mask - (1 << id)]);
        res += (f[mask] == SIZE);
    }
    cout << res;
}

int main() {
    tassk();
    solve();
    return 0;
}