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

int n, m;
char a[M][M];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
bool visited[M][M];
vll ans;
int sum = 0;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool check(int u, int v){
    return (1 <= u && u <= n && 1 <= v && v <= m);
}


int bfs(int x, int y){
    queue<pii> q;
    int dem = 0;
    bool ok = true;
    q.push({x, y});
    while (!q.empty()){
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        if (visited[cx][cy]) continue;
        visited[cx][cy] = 1;
        if (a[cx][cy] == 'W') dem++;
        for (int k = 0; k < 4; k++){
            int nx = cx + px[k];
            int ny = cy + py[k];
            if (check(nx, ny)){
                if (a[nx][ny] == 'W'){
                    q.push({nx, ny});
                }
                else if (a[nx][ny] == '.'){
                    ok = false;
                }
            }
        }    
    }
    if (ok) return dem;
    else return 0;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++){
            a[i][j] = s[j - 1];
        }
    }
    ll ans = 0;
    vpll tmp;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == 'W' && !visited[i][j]){
                int tmps = ans;
                ans += bfs(i, j);
                if (ans > tmps) tmp.pb({i, j});
            }
        }
    }
    cout << ans << el;
    /*for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << visited[i][j] << " ";
        }
        cout << el;
    }
    for (auto x : tmp) cout << x.first << " " << x.second << el;*/
    
}

int main() {
    tassk();
    solve(); 
    return 0;
}