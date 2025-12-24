
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

ll n, m;
bool visited[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void bfs(){
    queue<pll> q;
    q.push({n, 0});
    while (!q.empty()){
        ll u = q.front().first, dem = q.front().second;
        q.pop();
        if (u < 0 || u > N || visited[u]) continue;
        visited[u] = 1;
        if (u == m){
            cout << dem;
            return;
        }
        q.push({u * 2, dem + 1});
        q.push({u - 1, dem + 1});
    }
}

void solve() {
    cin >> n >> m;
    if (n >= m) cout << n - m << el;
    else bfs();
}

int main() {
    tassk();
    solve(); 
    return 0;
}
