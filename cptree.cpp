#include <bits/stdc++.h>
using namespace std;

#define task "195"
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
const ll M = 2e3 + 5;
const ll INF = 4e9;
const ll MOD = 1e8;

int n, tin[N], tout[N], timer = 0, ans = 0;
vector<int> adj1[N], adj2[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

struct SegmentTree{
    vector<int> st, lazy; int size;

    void init(int n){
        st.resize(4 * n + 5);
        lazy.resize(4 * n + 5);
        size = n;
    }

    void push(int id, int l, int r){
        if (lazy[id] == 0) return;
        st[id] += lazy[id];
        if (l != r){
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
        }
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        push(id, l, r);
        if (v < l || r < u) return; 
        if (u <= l && r <= v) {    
            lazy[id] += val;
            push(id, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
    }


    int get(int id, int l, int r, int pos){
        push(id, l, r);
        if (l == r) return st[id];
        int mid = (l + r) / 2;
        if (pos <= mid) return get(id * 2, l, mid, pos);
        return get(id * 2 + 1, mid + 1, r, pos);
    }


} Tree;

void dfs(int u){
    tin[u] = ++timer;
    for (int v : adj1[u]){
        dfs(v);
    }
    tout[u] = timer;
}

void dfs2(int u){
    ans += Tree.get(1, 1, n, tin[u]);
    Tree.update(1, 1, n, tin[u], tout[u], 1);
    for (int v : adj2[u]) dfs2(v);
    Tree.update(1, 1, n, tin[u], tout[u], -1);
}

void solve() {
    cin >> n; 
    int root1, root2;
    for (int i = 1; i <= n; i++){
        int p; cin >> p;
        if (p == 0) root1 = i;
        else adj1[p].pb(i);
    }
    for (int i = 1; i <= n; i++){
        int p; cin >> p;
        if (p == 0) root2 = i;
        else adj2[p].pb(i);
    }
    dfs(root1);
    Tree.init(n);
    dfs2(root2);
    cout << ans << el;
}

int main() {
    tassk();
    solve();
    return 0;
}
