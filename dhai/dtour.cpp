#include <bits/stdc++.h>
using namespace std;

#define task "dtour"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<int, int>> vpii;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;

const int N = 1e6 + 7;

int n, k, q;
vector<int> adj[N];
vector<int> cap[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool dfs(int u, int goal, int par, vector<int> &path) {
    if (u == goal) return true;
    for (int v : adj[u]) {
        if (v == par) continue;
        path.pb(v);
        if (dfs(v, goal, u, path)) return true;
        path.pop_back();
    }
    return false;
}

void solve() {
    cin >> n >> k >> q;
    for (int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        vector<int> path;
        path.pb(u);
        dfs(u, v, 0, path);
        cap[i] = path;
    }
    while (q--) {
        int s;
        cin >> s;
        vector<int> par(n + 1, -1);
        qll qu;
        qu.push(s);
        par[s] = 0;
        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            for (int v : adj[u]) {
                if (par[v] == -1) {
                    par[v] = u;
                    qu.push(v);
                }
            }
        }
        int ans = 0;
        for (int t = 1; t <= n; t++) {
            vector<bool> mark(n + 1, false);
            int x = t;
            while (x != 0) {
                mark[x] = true;
                x = par[x];
            }
            bool ok = false;
            for (int i = 1; i <= k && !ok; i++) {
                bool good = true;
                for (int node : cap[i]) {
                    if (!mark[node]) {
                        good = false;
                        break;
                    }
                }
                if (good) ok = true;
            }
            if (ok) ans++;
        }
        cout << ans << " ";
    }
    cout << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
