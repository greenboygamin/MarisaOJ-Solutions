#include <bits/stdc++.h>
using namespace std;

#define task "352"
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
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

int n, cnt[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}


void solve() {
    cin >> n;
    if (n == 1 || n == 2){
        cout << 1;
        return;
    }
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        cnt[u]++;
        cnt[v]++;
    }
    int maxs = 0;
    for (int i = 1; i <= n; i++){
        if (cnt[i] == 1) maxs++;
    }
    cout << maxs;
}

int main() {
    tassk();
    solve(); 
    return 0;
}