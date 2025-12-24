#include <bits/stdc++.h>
using namespace std;

#define task "131"
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
typedef pair<ld, pair<int, int>> edge;

const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int par[N], ranks[N];
int n, q;
bool visited[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void init(){
    for (int i = 1; i <= n; i++){
        par[i] = i;
        ranks[i] = i;
    }
}

int finds(int u){
    return par[u] == u ? u : (par[u] = finds(par[u]));
}

void unites(int u, int v){
    u = finds(u); v = finds(v);
    if (u != v){
        if (ranks[u] < ranks[v]) swap(u, v);
        par[v] = u;
        ranks[u] += ranks[v];
    }
}

void solve() {
    cin >> n >> q;
    init();
    while (q--){
        int type, u, v;
        cin >> type;
        if (type == 1){
            cin >> u >> v;
            unites(u, v);
        }
        else {
            cin >> u;
            u = finds(u);
            cout << ranks[u] << el;
        }
    }
}

int main() {
    tassk();
    solve(); 
    return 0;
}