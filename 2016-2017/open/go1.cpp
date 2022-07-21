#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 9;
long long P = 9973;

long long po[502];
long long h[502*2][502];

long long query(int num, int b, int e) {
    return (h[num][e+1] - (h[num][b] * po[e-b+1]) % MOD + MOD) % MOD;
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    po[0] = 1;
    for (int i = 1; i < 502; i++) {
        po[i] = (po[i-1] * P) % MOD;
    }
    for (int i = 0; i < 2*n; i++) {
        h[i][0] = 0;
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            h[i][j+1] = (h[i][j] * P + c) % MOD;
        }
    }
    int sol = INT_MAX;
    int k = (m+1) / 2;
    int l = 0;
    int r = m;
    while (l < r) {
        bool flag2 = false;
        for (int i = 1; i + k <= m; i++) {
            bool flag = true;
            set<long long> s;
            for (int j = 0; j < n; j++) {
                s.insert(query(j, i-1, i + k-1));
            }
            for (int j = 0 ; j < n; j++) {
                long long q = query(j+n,i-1,i+k-1);
                if (s.count(q)) {flag = false; break;}
            }
            if (!flag) {
                continue;
            }
            flag2 = true;
            break;
        }
        if (flag2) {
            sol = min(sol, k+1); 
            r = k;
            k = (r + l) / 2;

        } else {
            l = k+1;
            k = (r + l) / 2;

        }
    }
    cout << sol << endl;
}