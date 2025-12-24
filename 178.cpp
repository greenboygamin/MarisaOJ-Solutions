#include <bits/stdc++.h>
using namespace std;

#define task "178"
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
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 1e6 + 7;
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

int n;
ll a[101][101][101];
ll d[101][101][101];
int px[] = {0, 0, 1, 0, 0, -1};
int py[] = {0, 1, 0, 0, -1, 0};
int pz[] = {1, 0, 0, -1, 0, 0};

struct cu{
    ll dist, x, y, z;
    bool operator> (const cu &other) const{
        return dist > other.dist;
    }
};

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}
bool check(int x){
    return (1 <= x && x <= n);
}

void dijkstra(){
    memset(d, 0x3f, sizeof d);
    d[1][1][1] = 0;
    priority_queue<cu, vector<cu>, greater<cu>> kiu;
    kiu.push({0, 1, 1, 1});
    while (!kiu.empty()){
        auto [dist, cx, cy, cz] = kiu.top(); kiu.pop();
        if (dist > d[cx][cy][cz]) continue;
        for (int dir = 0; dir < 6; dir++){
            int nx = cx + px[dir];
            int ny = cy + py[dir];
            int nz = cz + pz[dir];
            if (check(nx) && check(ny) && check(nz) && d[nx][ny][nz] > d[cx][cy][cz] + a[nx][ny][nz]){
                d[nx][ny][nz] = d[cx][cy][cz] + a[nx][ny][nz];
                kiu.push({d[nx][ny][nz], nx, ny, nz});
            }
        }
    }
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                cin >> a[i][j][k];
            }
        }
    }
    dijkstra();
    cout << d[n][n][n] << el;
}

int main() {
    Task();
    Solve();
    return 0;
}