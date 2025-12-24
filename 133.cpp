#include <bits/stdc++.h>
using namespace std;

#define task "127"
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

int n, ranks[N], par[N], p[N];
bool visited[N];
vector<int> adj[N];

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
        ranks[i] = 1;
    }
}

int finds(int u){
    return (par[u] == u) ? u : (par[u] = finds(par[u]));
}

void unites(int u, int v){
    u = finds(u);
    v = finds(v);
    if (u != v){
        if (ranks[u] < ranks[v]) swap(u, v);
        par[v] = u;
        if (ranks[u] == ranks[v]) ranks[u]++;
    }
}

void solve() {
    cin >> n;
    init();
    //for (int i = 1; i <= n; i++) cout << par[i] << " ";
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        p[i] = finds(p[i]);
        cout << p[i] << " ";
        if (p[i] != n) par[p[i]] = p[i] + 1;
        else par[p[i]] = 1;
    }
}

int main() {
    tassk();
    solve(); 
    return 0;
}