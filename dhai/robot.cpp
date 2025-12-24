#include <bits/stdc++.h>
using namespace std;

#define task "robot"
#define el "\n"
#define pb push_back
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

typedef long long int ll;
typedef long double ld;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<int, int>> vpii;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef stack<ll> sll;
typedef queue<ll> qll;
typedef deque<ll> dqll;
typedef priority_queue<ll> pqll;
const ll N = 500;
const ll M = 2e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 123456789;
const ll OFFSET = 500000;
const ll SIZE = OFFSET * 2 + 1;

int n, m, k;
bool wall[M][M], visited[M][M], valid[M][M];
int px[] = {-1, 1, 0, 0};
int py[] = {0, 0, -1, 1};
char moves[] = {'U', 'D', 'L', 'R'};
char revs[] = {'D', 'U', 'R', 'L'};
struct coor {
    int u, v;
} a[N];
map<pii, pii> trace;
map<pii, char> tu;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void bfs() {
    queue<pii> q;
    q.push({0, 0});
    visited[0][0] = true;
    valid[0][0] = true;
    trace[{0, 0}] = {-1, -1};

    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + px[d];
            int ny = y + py[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (wall[nx][ny] || visited[nx][ny]) continue;
            visited[nx][ny] = true;
            valid[nx][ny] = true;
            trace[{nx, ny}] = {x, y};
            tu[{nx, ny}] = revs[d];
            q.push({nx, ny});
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        wall[x][y] = 1;
    }
    for (int i = 1; i <= k; i++) {
        cin >> a[i].u >> a[i].v;
    }

    bfs();
    vector<pii> S;
    for (int i = 1; i <= k; i++) S.pb({a[i].u, a[i].v});
    sort(S.begin(), S.end());
    S.erase(unique(S.begin(), S.end()), S.end());
    vector<char> res;
    while (S.size() > 1) {
        bool found = false;
        for (int d = 0; d < 4 && !found; d++) {
            vector<pii> news;
            for (auto temps : S) {
                int x = temps.first, y = temps.second;
                int nx = x + px[d], ny = y + py[d];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !wall[nx][ny]) {
                    news.pb({nx, ny});
                } else {
                    news.pb({x, y});
                }
            }
            sort(news.begin(), news.end());
            news.erase(unique(news.begin(), news.end()), news.end());
            bool ok = true;
            for (auto &p : news) {
                if (!valid[p.first][p.second]) {
                    ok = false;
                    break;
                }
            }
            if (ok && news.size() < S.size()) {
                res.pb(moves[d]);  
                S = news;              
                found = true;     
            }
        }
    }
    vector<char> ans;
    int x = S[0].first, y = S[0].second;
    while (trace[{x, y}].first != -1 && trace[{x, y}].second != -1) {
        ans.pb(tu[{x, y}]);
        pii tmp = trace[{x, y}];
        x = tmp.first;
        y = tmp.second;
    }
    reverse(ans.begin(), ans.end());
    for (char c : ans) res.pb(c);
    for (char c : res) cout << c;
    cout << endl;
}

int main() {
    tassk();
    solve();
    return 0;
}