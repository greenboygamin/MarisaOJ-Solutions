#include <bits/stdc++.h>
using namespace std;

#define task "493"
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
const ll MOD = 123456789;

string s, t;
int dem10 = 0, dem01 = 0, dem0h = 0, dem1h = 0, ans;

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve(){
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == t[i]) continue;
        if (s[i] == '1' && t[i] == '0') dem10++;
        else if (s[i] == '0' && t[i] == '1') dem01++;
        else if (s[i] == '?' && t[i] == '0') dem0h++;
        else if (s[i] == '?' && t[i] == '1') dem1h++;
    }
    ans = max(dem10, dem01) + dem0h + dem1h;
    cout << ans;
    
}


int main() {
    tassk();
    solve();
    return 0;
}