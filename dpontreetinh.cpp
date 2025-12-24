#include <bits/stdc++.h>
using namespace std;

#define task "230"
#define el "\n"
typedef long long ll;

const ll N = 205;
const ll K = 205;
const ll NEG_INF = (ll)(-9e18);

struct State {
    ll val, mn, mx;
};

int n, k;
ll a[N];
vector<int> adj[N];
vector<State> dp[N][K];

void dfs(int u, int p) {
    // base
    dp[u][0].push_back({0, a[u], a[u]});

    for (int v : adj[u]) if (v != p) {
        dfs(v, u);

        vector<State> ndp[K];
        for (int cu = 0; cu <= k; cu++) {
            for (auto &su : dp[u][cu]) {
                for (int cv = 0; cv + cu <= k; cv++) {
                    for (auto &sv : dp[v][cv]) {
                        // 1. giữ cạnh u-v
                        {
                            int nc = cu + cv;
                            State ns;
                            ns.val = su.val + sv.val;
                            ns.mn = min(su.mn, sv.mn);
                            ns.mx = max(su.mx, sv.mx);
                            ndp[nc].push_back(ns);
                        }
                        // 2. cắt cạnh u-v
                        if (cu + cv + 1 <= k) {
                            int nc = cu + cv + 1;
                            State ns;
                            ns.val = su.val + sv.val + (sv.mx - sv.mn);
                            ns.mn = su.mn; // component u giữ nguyên
                            ns.mx = su.mx;
                            ndp[nc].push_back(ns);
                        }
                    }
                }
            }
        }

        // compress: với mỗi c giữ max val cho từng (mn,mx)
        for (int c = 0; c <= k; c++) {
            if (ndp[c].empty()) continue;
            // giữ tốt nhất với cùng (mn,mx)
            map<pair<ll,ll>, ll> best;
            for (auto &s : ndp[c]) {
                auto key = make_pair(s.mn, s.mx);
                if (!best.count(key) || best[key] < s.val) best[key] = s.val;
            }
            dp[u][c].clear();
            for (auto &it : best) {
                dp[u][c].push_back({it.second, it.first.first, it.first.second});
            }
        }
    }
}

void tassk() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

int main() {
    tassk();
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);

    ll ans = NEG_INF;
    for (int c = 0; c <= k; c++) {
        for (auto &s : dp[1][c]) {
            ans = max(ans, s.val + (s.mx - s.mn));
        }
    }
    cout << ans << el;
    return 0;
}
