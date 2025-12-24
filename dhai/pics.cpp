#include <bits/stdc++.h>
using namespace std;

#define task "pics"
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

struct luki{
    int val, id;
} s[N];

int n, m;
int a, b, l, x;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

bool cmp(const luki &y, const luki &z){
    return y.val < z.val;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i].val, s[i].id = i;
    sort(s + 1, s + n + 1, cmp);
    for (int idx = 1; idx <= m; idx++) {
        int a, b, l;
        cin >> a >> b >> l;
        vector<bool> check(n + 1, false);
        while (l--) {
            int x; cin >> x;
            check[x] = true;
        }
        int A = a, B = b;
        int dem = 0;
        string res(n + 1, '0'); 
        for (int i = 1; i <= n; i++) {
            int id = s[i].id;
            int val = s[i].val;
            if (check[id]) continue;

            if (A >= val) {
                A -= val;
                dem++;
                if (idx == 1) res[id] = '1';
            }
            else if (B >= val) {    
                B -= val;
                dem++;
                if (idx == 1) res[id] = '2';
            }
            else if (a < val && b < val) break;
        }
        if (idx == 1) {
            cout << dem << el;
            for (int i = 1; i <= n; i++) {
                if (res[i] == '0') cout << '0';
                else cout << res[i];
            }
            cout << el;
        }
        else cout << dem << " ";
    }
}


int main() {
    tassk();
    solve();
    return 0;
}