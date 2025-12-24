#include <bits/stdc++.h>
using namespace std;

#define task "hopcroftkarp"
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
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 17;
const ll M = 2e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

int n, matchU[N], matchV[N], d[N];
vi adj[N];

struct edge{
    int u, v, w;
}; vector<edge> edges;

bool ss(const edge &x, const edge &y){
    return x.w > y.w;
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs(){
    queue<int> q;
    for (int u = 1; u <= n; u++){
        if (matchU[u] == 0){
            q.push(u);
            d[u] = 0;
        }
        else d[u] = INT_MAX;
    }
    bool ok = 0;
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (matchV[v] == 0) ok = 1;
            else if (d[matchV[v]] == INT_MAX){
                d[matchV[v]] = d[u] + 1;
                q.push(matchV[v]);
            }
        }
    }
    return ok;
}

bool dfs(int u){
    for (int v : adj[u]){
        if (matchV[v] == 0 || (d[matchV[v]] == d[u] + 1 && dfs(matchV[v]))){
            matchV[v] = u; matchU[u] = v;
            return true;
        }
    }
    d[u] = INT_MAX;
    return 0;
}

int hopcroft_karp(){
    int dem = 0;
    while (bfs()){
        for (int u = 1; u <= n; u++){
            if (matchU[u] == 0 && dfs(u)) dem++;
        }
    }
    return dem;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int val; cin >> val;
            edges.pb({i, j, val});
        }
    }
    sort(edges.begin(), edges.end(), ss);
    for (auto [u, v, w] : edges){
        for (int i = 1; i <= n; i++) {
            matchU[i] = matchV[i] = 0;
        }
        adj[u].pb(v);
        int ans = hopcroft_karp();
        if (ans == n) {
            cout << w << el;
            for (int u = 1; u <= n; u++) cout << matchU[u] << el;
            return;
        }
    }
}


int main() {
    tassk();
    solve();
    return 0;
}