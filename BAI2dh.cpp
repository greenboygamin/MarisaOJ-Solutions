#include <bits/stdc++.h>
using namespace std;

#define task ""
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
const ll N = 500;
const ll M = 2e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;
const ll OFFSET = 500000;
const ll SIZE = OFFSET * 2 + 1;

ll n;
vpll cows(N);
unordered_map<ll, ll> dp;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> cows[i].first >> cows[i].second;
    }
    dp[OFFSET * SIZE + OFFSET] = 0;
    for (pll tmp : cows){
        ll iq = tmp.first, eq = tmp.second;
        unordered_map<ll, ll> next = dp;
        for (auto &[key, val] : dp){
            ll iqs = key / SIZE - OFFSET;
            ll eqs = key % SIZE - OFFSET;
            ll iq_new = iqs + iq;
            ll eq_new = eqs + eq;
            ll total = val + iq + eq;
            if (-OFFSET <= iq_new && iq_new <= OFFSET && -OFFSET <= eq_new && eq_new <= OFFSET){
                ll key_new = ((iq_new + OFFSET) * SIZE + (eq_new + OFFSET));
                if (!next.count(key_new) || next[key_new] < total){
                    next[key_new] = total;
                }
            }
        }
        dp = move(next);
    }
    ll ans = 0;
    for (auto &[key, val] : dp) {
        ll iq_sum = key / SIZE - OFFSET;
        ll eq_sum = key % SIZE - OFFSET;
        if (iq_sum >= 0 && eq_sum >= 0) {
            ans = max(ans, val);
        }
    }

    cout << ans << endl;
}


int main() {
    tassk();
    solve();
    return 0;
}