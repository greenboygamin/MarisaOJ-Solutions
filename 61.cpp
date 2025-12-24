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

string s;
ll a[N];

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
}

void solve() {
    cin >> s;
    s = " " + s; ll dem = 0;
    unordered_map<ll, ll> c;
    c[0] = 1;
    ll sum = 0;
    int n = s.length() - 1;
    for (int i = 1; i <= n; i++){
        sum += (s[i] == '1' ? 1 : -1);
        if (c.count(sum)){
            dem += c[sum];
        }
        c[sum]++;
    }
    cout << dem;
}

int main() {
    tassk();
    solve(); 
    return 0;
}
