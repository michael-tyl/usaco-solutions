#include <bits/stdc++.h>

using namespace std;

vector<int> bit;

void update(int p, int v) {
    for (; p < bit.size(); p += p & -p) {
        bit[p] += v;
    }
}

int query(int p) {
    int q = 0;
    for (; p > 0; p -= p & -p) {
        q += bit[p];
    }
    return q;
}

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> seen(n, 0);
    bit = vector<int>(2*n + 1);
    vector<int> loc(n);
    long long sol = 0;
    for (int i = 0; i < 2 * n; i++) {
        int a; cin >> a;a--;
        if (seen[a] == 0) {
            seen[a]++;
            loc[a] = i+1;
            update(i+1, 1);
        } else {
            sol += query(i+1) - query(loc[a]);
            update(loc[a], -2);
            update(i+1, 1);
        }
    }
    sol /= 2;
    cout << sol << endl;
}