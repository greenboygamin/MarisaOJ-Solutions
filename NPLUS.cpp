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

typedef unsigned long long ull;
typedef pair<ull, ull> pull;

const ll N = 2e5 + 5; 
const ll M = 2e3 + 5;
const ll INF = 2e9;
const ll MOD = 1e9 + 7;


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}


void solve() {
    ull a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << el;
        return;
    }

    queue<pull> q;
    map<pull, int> dist;
    map<pull, pull> par;
    map<pull, string> op;

    q.push({a, b});
    dist[{a, b}] = 0;
    par[{a, b}] = {0, 0}; 

    pull target = {0, 0};

    while (!q.empty()) {
        pull cur = q.front();
        q.pop();
        ull u = cur.first;
        ull v = cur.second;

        if (u == v) {
            target = cur;
            break;
        }

        int d = dist[cur];
        if (d >= 5000) continue;
        
        // 1. Ngược của A+=B
        if (u > v && v != 0) {
            pull nxt = {u - v, v};
            if (dist.find(nxt) == dist.end()) {
                dist[nxt] = d + 1;
                par[nxt] = cur;
                op[nxt] = "A+=B"; 
                q.push(nxt);
            }
        }
        // 2. Ngược của B+=A
        if (v > u && u != 0) {
            pull nxt = {u, v - u};
            if (dist.find(nxt) == dist.end()) {
                dist[nxt] = d + 1;
                par[nxt] = cur;
                op[nxt] = "B+=A";
                q.push(nxt);
            }
        }
        // 3. Ngược của A+=A
        if (u > 0 && u % 2 == 0) {
            pull nxt = {u / 2, v};
            if (dist.find(nxt) == dist.end()) {
                dist[nxt] = d + 1;
                par[nxt] = cur;
                op[nxt] = "A+=A";
                q.push(nxt);
            }
        }
        // 4. Ngược của B+=B
        if (v > 0 && v % 2 == 0) {
            pull nxt = {u, v / 2};
            if (dist.find(nxt) == dist.end()) {
                dist[nxt] = d + 1;
                par[nxt] = cur;
                op[nxt] = "B+=B";
                q.push(nxt);
            }
        }
    }

    vector<string> ans;
    pull cur = target;
    
    while (par[cur].first != 0 || par[cur].second != 0) {
        ans.pb(op[cur]);
        cur = par[cur];
    }
    
    reverse(ans.begin(), ans.end());
    
    cout << ans.size() << el;
    for (const string& s : ans) {
        cout << s << el;
    }
}

int main() {
    tassk();
    solve();
    return 0;
}