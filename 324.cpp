#include <bits/stdc++.h>
using namespace std;

#define task "KNIGHT"
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
const ll INF = INT_MAX;
const ll MOD = 998244353;

int n, m, k;
int a[M][M];
int px[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int py[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void Task() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }
}

void backtrack(int cnt, int x, int y){
    if (cnt == n * m){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << el;
        }
        exit(0);
    }
    for (int k = 0; k < 8; k++){
        int nx = x + px[k];
        int ny = y + py[k];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[nx][ny] == 0){
            a[nx][ny] = cnt + 1;
            backtrack(cnt + 1, nx, ny);
            a[nx][ny] = 0;
        }
    }
}

void Solve() {
    cin >> n >> m;
    a[1][1] = 1;
    backtrack(1, 1, 1);
}

int main() {
    Task();
    Solve();
    return 0;
}
