#include <bits/stdc++.h>
using namespace std;

#define task "175"
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
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

int n, m, ways[N];
vector<ll> d1, dn;
vector<pll> adj[N];

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void dijkstra(int src, vector<ll> &d){
    d[src] = 0;
    ways[src] = 1;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, src});
    while (!kiu.empty()){
        auto [du, u] = kiu.top(); kiu.pop();
        if (du > d[u]) continue;
        for (auto [v, val] : adj[u]){
            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                ways[v] = ways[u];
                kiu.push({d[v], v});
            }
            else if (d[v] == d[u] + val){
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }
}

void Solve() {
    cin >> n >> m;
    d1.assign(n + 1, INF); dn.assign(n + 1, INF);
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijkstra(1, d1);
    cout << ways[n];
}

int main() {
    Task();
    Solve();
    return 0;
}