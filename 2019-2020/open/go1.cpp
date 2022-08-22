#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5 + 5;

int bit[MN];

void update(int p, int v) {
    while (p < MN) {
        bit[p] += v;
        p += p & -p;
    }
}

long long query(int p) {
    long long ans = 0;
    while (p > 0) {
        ans += bit[p];
        p -= p & -p;
    }
    return ans;
}

int main() {
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> h(n+1);
    for (int i = 0; i < n; i++) {
        update(i+1, 1);
        cin >> a[i];
        h[a[i]].push_back(i); 
    }

    for (int i = 0; i < n; i++) {
        sort(h[i].begin(), h[i].end());
    }

    long long sol = 0;
    for (int j = 0; j < n; j++) {
        cout << sol << "\n";
        for (int i = 0; i < h[j].size(); i++) {
            int ind = h[j][i];
            sol += query(ind);
            update(ind + 1, -1);
        }
    }
}