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

ll n, x, ans = 0, prefix[N];
unordered_map<ll, ll> mp;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++){
        int tmp; cin >> tmp;
        prefix[i] = prefix[i - 1] + tmp;
        mp[prefix[i]]++;
        ans += mp[prefix[i] - x];
    }
    cout << ans;
}

int main() {
    tassk();
    solve(); 
    return 0;
}
