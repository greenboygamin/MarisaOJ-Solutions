#include <bits/stdc++.h>
using namespace std;

#define task "SPACE" 
#define el "\n"
#define pb push_back
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
const ll N = 2e6 + 7;
const ll M = 2e3 + 7;
const ll B = 505;
const ll INF = 0x3f3f3f3f3f3f;
const ll MOD = 2e18;

struct pt {
    ld x, y, z;
};

int n;
pt p[105];

ld dist(pt a, pt b) {
    ld dx = a.x - b.x;
    ld dy = a.y - b.y;
    ld dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

ld total_dist(pt center) {
    ld total = 0;
    for (int i = 0; i < n; i++) {
        total += dist(center, p[i]);
    }
    return total;
}

void tassk() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen(task".inp", "r")) {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
}

void solve() {
  cin >> n;
    pt center = {0, 0, 0};
  for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        center.x += p[i].x;
        center.y += p[i].y;
        center.z += p[i].z;
    }
    
    center.x /= n;
    center.y /= n;
    center.z /= n;
    
    ld step = 1000.0;
    ld min_d = total_dist(center);
    
    for (int iter = 0; iter < 50000; iter++) {
        pt grad = {0, 0, 0};
        
        for (int i = 0; i < n; i++) {
            ld d = dist(center, p[i]);
            if (d > 1e-9) { 
                grad.x += (p[i].x - center.x) / d;
                grad.y += (p[i].y - center.y) / d;
                grad.z += (p[i].z - center.z) / d;
            }
        }
        
        pt next_p = {
            center.x + grad.x * step,
            center.y + grad.y * step,
            center.z + grad.z * step
        };
        
        ld next_d = total_dist(next_p);
        
        if (next_d < min_d) {
            min_d = next_d;
            center = next_p;
        }
        
        step *= 0.99; 
    }
    
    cout << fixed << setprecision(4) << center.x << " " << center.y << " " << center.z << el;
}

int main() {
  tassk(); 
  solve();
  return 0;
}