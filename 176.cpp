#include <bits/stdc++.h>
using namespace std;

#define task "SORT"
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
const ll MOD = 998244353;

int n, m, k;
ll d[N][6];
vector<pll> adj[N];


struct cu{
    ll dist, node, used;
    bool operator> (const cu &other) const{
        return dist > other.dist;
    }
};

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void dijkstra(){
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= k; j++) d[i][j] = INF;
    }
    for (int i = 0; i <= k; i++) d[1][i] = 0;
    priority_queue<cu, vector<cu>, greater<cu>> kiu;
    kiu.push({0, 1, 0});
    while (!kiu.empty()){
        auto [du, u, used_u] = kiu.top(); kiu.pop();
        if (du > d[u][used_u]) continue;
        for (auto [v, val] : adj[u]){
            if (d[v][used_u] > d[u][used_u] + val){
                d[v][used_u] = d[u][used_u] + val;
                kiu.push({d[v][used_u], v, used_u});
            }
            if (used_u + 1 <= k){
                ll used_v = used_u + 1;
                if (d[v][used_v] > d[u][used_u]){
                    d[v][used_v] = d[u][used_u];
                    kiu.push({d[v][used_v], v, used_v});
                }
            }
        }
    }
}

void Solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijkstra(); 
    ll mins = INF;
    for (int i = 0; i <= k; i++) mins = min(mins, d[n][i]);
    if (mins == INF) cout << -1;
    else cout << mins;
}

int main() {
    Task();
    Solve();
    return 0;
}