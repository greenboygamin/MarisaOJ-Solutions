#include <bits/stdc++.h>
using namespace std;

#define el "\n"
#define task ""
#define pb push_back

typedef long long int ll;
const ll INF = 4e18;
const ll N = 1e6 + 7;
const ll M = 2e3 + 7;

int n, k;

struct point{
    int x, y;
} a[1005];

bool ss(const point &z, const point &t){
    return z.x < t.x;
}

void tassk(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1, ss);
    int ans = 1e9;
    for (int i = 1; i <= n; i++){
        vector<int> q;
        for (int j = i; j <= n; j++){
            int it = lower_bound(q.begin(), q.end(), a[j].y) - q.begin();
            q.insert(q.begin() + it, a[j].y);
            if (q.size() >= k){
                for (int pos = 0; pos + k - 1 < q.size(); pos++){
                    int miny = q[pos];
                    int maxy = q[pos + k - 1];
                    int area = (a[j].x - a[i].x) * (maxy - miny);
                    ans = min(ans, area);
                }
            }
        }
    }
    cout << ans;
}

int main(){
    tassk();
    solve();
    return 0;
}