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
const ll N = 2e5 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

int n, m, ways[N];
ll d[N][11];
vector<pll> adj[N];

struct cu{
    ll cost, node, prev_w;
    bool operator> (const cu &other) const{
        return cost > other.cost;
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
    priority_queue<cu, vector<cu>, greater<cu>> kiu;
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= 10; j++){
            d[i][j] = INF;
        }
    }
    d[1][0] = 0;
    kiu.push({0, 1, 0});
    while (!kiu.empty()){
        auto [du, u, prev_w] = kiu.top(); kiu.pop();
        if (du > d[u][prev_w]) continue;
        if (prev_w == 0){
            for (auto [v, w] : adj[u]){
                if (d[v][w] > du){
                    d[v][w] = du;
                    kiu.push({d[v][w], v, w});
                }
            }
        }
        else {
            for (auto [v, w] : adj[u]){
                if (d[v][0] > du + w * prev_w){
                    d[v][0] = du + w * prev_w;
                    kiu.push({d[v][0], v, 0});
                }
            }
        }
    }
    if (d[n][0] == INF) cout << -1 << el;
    else cout << d[n][0] << el;
}

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijkstra();
}

int main() {
    Task();
    Solve();
    return 0;
}