#include <bits/stdc++.h>
using namespace std;

#define task "hopcroftkarp"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 17;
const ll M = 2e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;

int n, m, matchU[N], matchV[N], d[N], cnt = 0, cntL = 0, cntR = 0, id[M][M], idL[N], idR[N];
vi adj[N];
bool has[M][M];
int px[] = {1, -1, 0, 0};
int py[] = {0, 0, -1, 1};


void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool bfs(){
    queue<int> q;
    for (int u = 1; u <= cntL; u++){
        if (matchU[u] == 0){
            d[u] = 0;
            q.push(u);
        }
        else d[u] = INT_MAX;
    }
    bool ok = 0;
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (matchV[v] == 0) ok = 1;
            else if (d[matchV[v]] == INT_MAX){
                d[matchV[v]] = d[u] + 1;
                q.push(matchV[v]);
            }
        }
    }
    return ok;
}

bool dfs(int u){
    for (int v : adj[u]){
        if (matchV[v] == 0 || (d[matchV[v]] == d[u] + 1 && dfs(matchV[v]))){
            matchV[v] = u; matchU[u] = v;
            return true;
        }
    }
    d[u] = INT_MAX;
    return false;
}

int hopcroft_karp(){
    int res = 0;
    while (bfs()){
        for (int u = 1; u <= cntL; u++){
            if (matchU[u] == 0 && dfs(u)) res++;
        }
    }
    return res;
}

void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            id[i][j] = ++cnt;
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= m; j++){
            if ((i + j) % 2 == 0){
                idL[id[i][j]] = ++cntL;
            }
            else idR[id[i][j]] = ++cntR;
        }
    }
    vector<pii> mush;
    for (int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        has[x][y] = 1;
        mush.pb({x,y});
    }
    for (auto [x,y] : mush){
        if ((x + y) % 2 == 0){
            int u = idL[id[x][y]];
            for (int k = 0; k < 4; k++){
                int nx = x + px[k], ny = y + py[k];
                if (nx < 1 || nx > m || ny < 1 || ny > m) continue;
                if (!has[nx][ny]) continue;
                int v = idR[id[nx][ny]];
                if (v) adj[u].pb(v);
            }
        }
    }
    cout << n - hopcroft_karp();
    
}


int main() {
    tassk();
    solve();
    return 0;
}