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

int n, m;
char a[M][M];
bool visited[M][M];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
vll ans; 

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}
bool check(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

int bfs(int i, int j){
    int sum = 0;
    if (a[i][j] == 'x') sum++;
    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++){
            int nx = cx + px[k];
            int ny = cy + py[k];
            if (!visited[nx][ny] && check(i, j)){
                visited[nx][ny] = 1;
                if (a[nx][ny] == 'x'){
                    sum++;
                    q.push({nx, ny});
                }
                if (a[nx][ny] == '.'){
                    q.push({nx, ny});
                }
                if (a[nx][ny] == '#') continue;
            }
        }
    }
    return sum;
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
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (!visited[i][j] && a[i][j] != '#'){
                ans.pb(bfs(i, j));
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) if (i != 0) cout << i << " ";
}

int main() {
    tassk();
    solve(); 
    return 0;
}
