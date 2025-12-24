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

int n, m, c[N];
ll d[N], d1[N], D[N], mins[N], p[N];
bool visited[N];
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

void dijkstra(){
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, 1});
    fill(d, d + N, INF);
    d[1] = 0;
    while (!kiu.empty()){
        ll du = kiu.top().first, u = kiu.top().second;
        kiu.pop();
        if (du > d[u]) continue;
        for (auto cur : adj[u]){
            ll v = cur.first, val = cur.second;
            if (d[v] > d[u] + val){
                d[v] = d[u] + val;
                kiu.push({d[v], v});
            }
        }
    }
}

void dijkstra1(){
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, n});
    fill(d1, d1 + N, INF);
    d1[n] = 0;
    while (!kiu.empty()){
        ll du = kiu.top().first, u = kiu.top().second;
        kiu.pop();
        if (du > d1[u]) continue;
        for (auto cur : adj[u]){
            ll v = cur.first, val = cur.second;
            if (d1[v] > d1[u] + val){
                d1[v] = d1[u] + val;
                kiu.push({d1[v], v});
            }
        }
    }
}


void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w}); adj[v].pb({u, w});
    }
    dijkstra();  
    dijkstra1();  
    priority_queue<pll, vpll, greater<pll>> kiu;
    for (int i = 1; i <= n; i++){
        D[i] = d[i] + d1[i];
        kiu.push({D[i], i});
    }
    while (!kiu.empty()){
        auto [Du, u] = kiu.top();
        kiu.pop();
        if (Du > D[u]) continue;
        for (auto [v, val] : adj[u]){
            if (D[v] > D[u] + val){
                D[v] = D[u] + val;
                kiu.push({D[v], v});
            }
        }
    }
    ll ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, D[i] + c[i]);
    cout << ans;
}

int main() {
    Task();
    Solve();
    return 0;
}