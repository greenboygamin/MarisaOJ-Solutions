#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task "prim"
#define pb push_back

typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;

const ll N = 1e6 + 7;
const ll M = 1e4 + 7;


ll n, m, d[N];
vector<pair<ll, ll>> adj[N];
bool visited[N];

void tassk(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void prim(){
    fill(d, d + N, 1e9);
    priority_queue<pll, vpll, greater<pll>> kiu;
    kiu.push({0, 1});
    d[1] = 0;
    while (!kiu.empty()){
        ll u = kiu.top().second;
        kiu.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto cur : adj[u]){
            ll v = cur.first;
            ll val = cur.second;
            if (!visited[v] && d[v] > val){
                d[v] = val;
                kiu.push({d[v], v});
            }
        }
    }

}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
    prim();
    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += d[i];
    cout << sum;

}

int main(){
    tassk();
    solve();
    return 0;
}