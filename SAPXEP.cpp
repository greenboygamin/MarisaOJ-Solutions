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

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
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
