#include <bits/stdc++.h>
using namespace std;

#define task "BAI4"
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
const ll Z = 3e2 + 7;
const ll TMP = 1e5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

string r_str;
ll dp[100005][11][2][2][2];
int l;
vector<int> r_digits;

ll solve_len(int len) {
    if (len == 0) return 0;
    if (len == 1) return 9;

    int half = (len + 1) / 2;
    ll f[half + 1][10];
    memset(f, 0, sizeof(f));
    
    for (int d = 1; d <= 9; d++) f[1][d] = 1;

    if (len == 2) {
        ll ans = 0;
        for (int d = 1; d <= 9; d++) {
            if (abs(d - d) >= 5) ans = (ans + f[1][d]) % MOD;
        }
        return ans;
    }

    for (int i = 2; i <= half; i++) {
        for (int prev_d = 0; prev_d <= 9; prev_d++) {
            if (i == 2 && prev_d == 0) continue; 
            if (f[i - 1][prev_d] == 0) continue;
            for (int d = 0; d <= 9; d++) {
                if (abs(d - prev_d) >= 5) {
                    f[i][d] = (f[i][d] + f[i - 1][prev_d]) % MOD;
                }
            }
        }
    }
    
    ll ans = 0;
    for (int d = 0; d <= 9; d++) ans = (ans + f[half][d]) % MOD;
    return ans;
}

ll dfs(int idx, int prev_d, bool tight_l, bool tight_r, bool is_lz) {
    int half = (l + 1) / 2;
    if (idx == half) return 1;

    if (!is_lz && dp[idx][prev_d + 1][tight_l][tight_r][is_lz] != -1) {
        return dp[idx][prev_d + 1][tight_l][tight_r][is_lz];
    }

    ll ans = 0;
    int limit = tight_l ? r_digits[idx] : 9;

    for (int d = 0; d <= limit; d++) {
        if (is_lz && d == 0) {
            int sym_idx = l - 1 - idx;
            bool n_tight_r = tight_r && (d == r_digits[sym_idx]);
            ans = (ans + dfs(idx + 1, -1, tight_l && (d == limit), n_tight_r, true)) % MOD;
        } else {
            if (!is_lz && abs(d - prev_d) < 5) continue;
            
            int sym_idx = l - 1 - idx;
            
            bool n_tight_l = tight_l && (d == r_digits[idx]);
            
            if (n_tight_l && tight_r && (d > r_digits[sym_idx])) {
                continue;
            }
            
            bool n_tight_r = tight_r && (d == r_digits[sym_idx]);
            
            ans = (ans + dfs(idx + 1, d, n_tight_l, n_tight_r, false)) % MOD;
        }
    }
    
    if (!is_lz) dp[idx][prev_d + 1][tight_l][tight_r][is_lz] = ans;
    return ans;
}


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n_ll;
        cin >> n_ll;
        
        r_str = to_string(n_ll);
        l = r_str.length();
        r_digits.resize(l);
        for(int i=0; i<l; i++) r_digits[i] = r_str[i] - '0';
        
        ll ans = 0;
        for (int len = 1; len < l; len++) {
            ans = (ans + solve_len(len)) % MOD;
        }

        memset(dp, -1, sizeof(dp));
        
        ans = (ans + dfs(0, -1, true, true, true)) % MOD;
        
        ans = (ans - 1 + MOD) % MOD; 
        
        cout << ans << el;
    }
}

int main() {
    tassk(); 
    solve();
    return 0;
}