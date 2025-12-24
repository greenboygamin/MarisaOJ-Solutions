#include <bits/stdc++.h>
using namespace std;

#define task "341"
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
const ll M = 1e3 + 7;
const ll B = 131;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 1e7 + 1203;

ll n, m, a[N], f[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[1] = 1;
    int res = 1;
    for (int i = 2; i <= n; i++){
        int l = 1, r = res, j = 0;
        while (l <= r){
            int mid = (l + r) / 2;
            if (a[i] > a[f[mid]]){
                j = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if (res == j) f[++res] = i;
        if (a[f[j + 1]] > a[i]) f[j + 1] = i;
    }
    //for (int i = 1; i <= n; i++) cout << f[i] << " "; cout << el;
    cout << res;
}

int main() {
    tassk();
    solve();
    return 0;
}
