#include <bits/stdc++.h>
using namespace std;

#define task "230"
#define el "\n"
#define pb push_back
typedef long long ll;

const ll N = 2005;
const ll INF = -1e18;

ll n;
ll a[N];
vector<int> adj[N];

ll dp[N];     // giá trị tối ưu trong subtree u
ll mn[N], mx[N]; // min/max của component chứa u

void dfs(int u, int p) {
    dp[u] = 0;
    mn[u] = mx[u] = a[u];

    for (int v : adj[u]) if (v != p) {
        dfs(v, u);

        // --- Giữ cạnh u-v (merge) ---
        ll keep_dp = dp[u] + dp[v];
        ll keep_mn = min(mn[u], mn[v]);
        ll keep_mx = max(mx[u], mx[v]);

        // --- Cắt cạnh u-v ---
        ll cut_dp = dp[u] + dp[v] + (mx[v] - mn[v]);
        ll cut_mn = mn[u];
        ll cut_mx = mx[u];

        // chọn tốt nhất
        if (cut_dp > keep_dp) {
            dp[u] = cut_dp;
            mn[u] = cut_mn;
            mx[u] = cut_mx;
        } else {
            dp[u] = keep_dp;
            mn[u] = keep_mn;
            mx[u] = keep_mx;
        }
    }

    dp[u] += (mx[u] - mn[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, -1);
    cout << dp[1] << el;
}
