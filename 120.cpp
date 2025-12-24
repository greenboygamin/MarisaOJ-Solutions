
#include <bits/stdc++.h>
using namespace std;

#define task ""
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
typedef long double ld;
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

ll n, m, color[N];
vll adj[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs(ll i){
    qll q;
    q.push(i);
    color[i] = 1;
    while (!q.empty()){
        ll u = q.front(); q.pop();
        for (auto v : adj[u]){
            if (color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    memset(color, -1, sizeof color);
    for (int i = 1; i <= n; i++){
        if (color[i] == -1 && !bfs(i)){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main() {
    tassk();
    solve(); 
    return 0;
}
