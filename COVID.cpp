#include <bits/stdc++.h>
using namespace std;

#define task "COVID"
#define el "\n"
#define pb push_back
typedef long long int ll;

const int MAXN = 1000; 

void tassk() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
}

string interact(const vector<vector<int>>& kits) {
    for (int k = 0; k < 10; k++) {
        cout << kits[k].size();
        for (int p : kits[k]) {
            cout << " " << p;
        }
        cout << el;
    }
    cout.flush();

    string res;
    cin >> res;
    return res;
}

void solve_sub1() {
    vector<vector<int>> kits(10);
    for (int k = 0; k < 10; k++) {
        for (int j = 1; j <= MAXN; j++) {
            if ((j >> k) & 1) {
                kits[k].push_back(j);
            }
        }
    }

    string res = interact(kits);
    
    int ans = 0;
    for (int k = 0; k < 10; k++) {
        if (res[k] == '+') {
            ans |= (1 << k);
        }
    }
    cout << ans << el;
}

void solve_sub2() {
    vector<vector<int>> kits(10);
    vector<bool> in_kit[10];
    for(int k=0; k<10; k++) in_kit[k].resize(MAXN + 1, false);

    for (int k = 0; k < 10; k++) {
        for (int i = 1; i <= MAXN - 1; i++) {
            if ((i >> k) & 1) {
                in_kit[k][i] = true;
                in_kit[k][i + 1] = true;
            }
        }
        for (int j = 1; j <= MAXN; j++) {
            if (in_kit[k][j]) {
                kits[k].push_back(j);
            }
        }
    }

    string res = interact(kits);
    
    int i_ans = 0;
    for (int k = 0; k < 10; k++) {
        if (res[k] == '+') {
            i_ans |= (1 << k);
        }
    }
    
    cout << i_ans << el; 
}

void solve_sub3() {
    vector<vector<int>> kits(10);
    const int NUM_PAIRS = MAXN / 2;

    for (int k = 0; k < 9; k++) {
        for (int p = 1; p <= NUM_PAIRS; p++) {
            if ((p >> k) & 1) {
                kits[k].push_back(2 * p - 1);
                kits[k].push_back(2 * p);
            }
        }
    }
    
    for (int j = 1; j <= MAXN; j += 2) {
        kits[9].push_back(j);
    }

    string res = interact(kits);
    
    int p_ans = 0;
    for (int k = 0; k < 9; k++) {
        if (res[k] == '+') {
            p_ans |= (1 << k);
        }
    }

    if (p_ans == 0) {
        cout << 0 << el;
    } else {
        if (res[9] == '+') {
            cout << (2 * p_ans - 1) << el;
        } else {
            cout << (2 * p_ans) << el;
        }
    }
}

void solve() {
    int T;
    if (!(cin >> T)) return; 
    
    for (int tc = 0; tc < T; ++tc) {
        int subtask = tc % 3;
        
        if (subtask == 0) {
            solve_sub1();
        } else if (subtask == 1) {
            solve_sub2();
        } else {
            solve_sub3();
        }
        cout.flush();
    }
}

int main() {
    tassk();
    solve();
    return 0;
}
