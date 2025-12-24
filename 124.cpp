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
const ll N = 1e6 + 5;
const ll M = 1e3 + 5;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e9 + 7;

struct points{
    ld x, y;
} a[N];

ll n;
ll d[M][M];  
vector<ll> adj[N];
bool visited[N];

ld calc(ld x1, ld x2, ld y1, ld y2){
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs(ld r){
    memset(visited, 0, sizeof visited);
    r = 4 * r * r;
    queue<ll> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()){
        ll u = q.front();
        q.pop();
        for (auto v : adj[u]){
            if (!visited[v] && d[u][v] <= r){
                visited[v] = 1;
                q.push(v);
            }
        }
    } 
    for (int i = 1; i <= n; i++){
        if (!visited[i]) return false;
    }
    return true;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (i != j) {
                d[i][j] = d[j][i] = calc(a[i].x, a[j].x, a[i].y, a[j].y);
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    ld l = 0, r = 1e9 + 4, ans;
    while (r - l >= 1e-9) {
        ld mid = (l + r) / 2;
        if (bfs(mid)){
            r = mid;
            ans = mid;
        }
        else l = mid;
    }
    cout << fixed << setprecision(6) << ans;
}

int main() {
    tassk();
    solve(); 
    return 0;
}