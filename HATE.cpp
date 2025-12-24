#include <bits/stdc++.h>
using namespace std;

#define task "HATE"
#define el "\n"
#define pb push_back
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
const ll N = 1e5 + 5;
const ll M = 2e3 + 7;
const ll B = 505;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

int n;
ll a[N];
int b[N];
vector<int> rev[N];
ll dp[N][2];
int vis[N];
int on_stack[N];
ll total_ans;

void tassk()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void dfs_tree(int u) {
    vis[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (int v : rev[u]) {
        if (on_stack[v] == 1) continue;
        if (!vis[v]) dfs_tree(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

ll solve_cycle_vec(const vector<int>& cyc) {
    int k = cyc.size();
    vector<ll> d0(k), d1(k);
    for (int i = 0; i < k; i++) {
        int u = cyc[i];
        d0[i] = dp[u][0];
        d1[i] = dp[u][1];
    }

    ll f0 = d0[0], f1 = -INF;
    for (int i = 1; i < k; i++) {
        ll nf0 = max(f0, f1) + d0[i];
        ll nf1 = f0 + d1[i];
        f0 = nf0;
        f1 = nf1;
    }
    ll ansA = max(f0, f1);

    f0 = -INF;
    f1 = d1[0];
    for (int i = 1; i < k; i++) {
        ll nf0 = max(f0, f1) + d0[i];
        ll nf1 = f0 + d1[i];
        f0 = nf0;
        f1 = nf1;
    }
    ll ansB = f0;

    return max(ansA, ansB);
}

void dfs_fc(int u) {
    vis[u] = 1;
    on_stack[u] = 1;

    int v = b[u];
    if (v == -1) {
        dfs_tree(u);
        total_ans += max(dp[u][0], dp[u][1]);
        on_stack[u] = 0;
        return;
    }

    if (!vis[v]) dfs_fc(v);
    if (on_stack[v] == 1) {
        vector<int> cyc;
        int c = v;
        do {
            cyc.pb(c);
            c = b[c];
        } while (c != v);

        for (int x : cyc) dfs_tree(x);

        total_ans += solve_cycle_vec(cyc);

        for (int x : cyc) on_stack[x] = 0;
    }

    if (on_stack[u] == 1) {
        dfs_tree(u);
        total_ans += max(dp[u][0], dp[u][1]);
        on_stack[u] = 0;
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            rev[i].clear();
            vis[i] = 0;
            on_stack[i] = 0;
            dp[i][0] = dp[i][1] = 0;
        }

        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            if (b[i] != -1) rev[b[i]].pb(i);
        }

        total_ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) dfs_fc(i);
        }

        cout << total_ans << "\n";
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}