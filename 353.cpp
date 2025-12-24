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

int n, m, k, a[N], d[N], ans = 0;
vector<int> adj[N];
string ss;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void bfs(int s) {
    fill(d, d + n + 1, 1e9);
    d[s] = (ss[1] == '0') ? 1 : -1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (d[v] == 1e9) {
                d[v] = (ss[v] == '0') ? (d[u] + 1) : (d[u] - 1);
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n; 
    cin >> ss;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ss = " " + ss;
    bfs(1);
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (d[i] > 0) dem++; 
    }
    
    cout << dem;
    
}

int main() {
    tassk();
    solve(); 
    return 0;
}