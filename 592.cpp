#include <bits/stdc++.h>
using namespace std;

#define task "127"
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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n, a[N], d[N];
bool visited[N];
vpll adj[N];
ll ans = 0;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void prim(){
    fill(d, d + n + 1, INF);
    d[0] = 0;
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, 0});
    while (!kiu.empty()){
        ll u = kiu.top().second, costs = kiu.top().first;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        ans += costs;
        for (auto cur : adj[u]){
            int v = cur.first, val = cur.second;
            if (d[v] > val && !visited[v]){
                d[v] = val;
                kiu.push({d[v], v});
            }
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        adj[0].pb({i, x});
        adj[i].pb({0, x});
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (i == j) continue;
            adj[i].pb({j, x});
        }
    }
    prim();
    cout << ans << el;
    //for (int i = 1; i <= n; i++) cout << d[i] << " ";
}

int main() {
    tassk();
    solve(); 
    return 0;
}