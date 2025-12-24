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

int n, m, trace[N];
ll d[N];
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
    fill(trace, trace + N, -1);
    d[1] = 0;
    while (!kiu.empty()){
        ll du = kiu.top().first, u = kiu.top().second;
        kiu.pop();
        if (du > d[u]) continue;
        for (auto cur : adj[u]){
            ll v = cur.first, val = cur.second;
            if (d[v] > d[u] + val){
                trace[v] = u;
                d[v] = d[u] + val;
                kiu.push({d[v], v});
            }
        }
    }
}

void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w}); adj[v].pb({u, w});
    }
    dijkstra();  
    if (d[n] == INF){
        cout << -1 << el;
        return;
    }
    int i = n; vi ans;
    while (i > 0){
        ans.pb(i); i = trace[i];
    }
    reverse(ans.begin(), ans.end());
    cout << d[n] << el;
    for (auto i : ans) cout << i << " ";
}


int main() {
    Task();
    Solve();
    return 0;
}