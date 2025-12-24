#include <bits/stdc++.h>
using namespace std;

#define task "schedule"
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

int n, lefts, rights, dp[N];

struct meeting{
    int l, r;
} a[N];

bool ss(const meeting &x, const meeting &y){
    return x.r < y.r;
}

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void sub1(){
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (a[i].l >= a[j].r){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxs = 0;
    for (int i = 1; i <= n; i++) maxs = max(maxs, dp[i]);
    cout << maxs;
}

void sub2(){
    int dem = 1;
    lefts = a[1].l, rights = a[1].r;
    for (int i = 2; i <= n; i++){
        if (a[i].l >= rights){
            rights = a[i].r;
            dem++;
        }
    }
    cout << dem;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + n + 1, ss);
    if (n <= 1000){
        sub1();
    }
    else sub2();
}

int main() {
    tassk();
    solve();
    return 0;
}