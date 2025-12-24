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

int n, m, sz[N], par[N], ans[N];
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
    for (int i = 1; i <= n * 2; i++){
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
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++){
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1){
            unite(v, u + n);
            unite(u, v + n);
        }
        if (type == 2){
            int fuA = finds(u), fvA = finds(v), fuB = finds(u + n), fvB = finds(v + n);
            if (fuA == fvA || fuB == fvB) cout << "SAFE";
            else if (fuA == fvB || fvA == fuB) cout << "FATAL";
            else cout << "DUNNO";
            cout << el;
        }
    }
    
}

int main() {
    tassk();
    solve(); 
    return 0;
}