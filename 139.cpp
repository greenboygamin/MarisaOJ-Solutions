#include <bits/stdc++.h>
using namespace std;

#define task "318"
#define el "\n"
#define pb push_back
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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n, q, sz[N], par[N], f[N];
bool ok[N];
struct edge{
    int u, v, w, idx;
    bool operator< (const edge &others) const{
        return w < others.w;
    }
};
vector<edge> edges;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    for (int i = 0; i <= 2 * (n + 1); i++){
        sz[i] = 1;
        par[i] = i;
    }
}

int finds(int u){
    return (par[u] == u) ? u : (par[u] = finds(par[u]));
}

void unite(int u, int v){
    u = finds(u);
    v = finds(v);
    if (u != v){
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v]; 
    }
}

void solve() {
    cin >> n >> q;
    int base = n + 1;
    int k = 1;
    init();
    for (int i = 1; i <= q; i++){
        int l, r, t;
        cin >> l >> r >> t;
        if (t == 0){
            if (finds(r) == finds(l + base - 1) || finds(r + base) == finds(l - 1)) break;
            unite(r, l - 1);
            unite(r + base, l + base - 1);
        }
        if (t == 1){
            if (finds(r) == finds(l - 1) || finds(r + base) == finds(l + base - 1)) break;
            unite(r, l - 1 + base);
            unite(r + base, l - 1);
        }
        k = i;
    }
    cout << k;
}

int main() {
    tassk();
    solve(); 
    return 0;
}