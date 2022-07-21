#include <bits/stdc++.h>

using namespace std;

int tree[200005];
int n;

void build() {
    int i = n - 1;
    while (i > 0) {
        tree[i] = max(tree[i<<1], tree[i<<1|1]);
        i--;
    }
}

void update(int p, int v) {
    p += n;
    tree[p] = max(tree[p], v);
    while (p > 1) {
        tree[p>>1] = max(tree[p], tree[p^1]);
        p >>= 1;
    }
}

int query(int l, int r) {
    int ans = 0;
    l += n; r += n;
    while (l < r) {
        if (l&1) ans = max(ans, tree[l++]);
        if (r&1) ans = max(ans, tree[--r]);
        l >>=1; r >>= 1;
    }
    return ans;
}

int main() {
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    long long m; cin >> n >>m;
    memset(tree, 0, sizeof(tree));
    vector<int> f(n);
    // vector<int> s(n);
    for (int i = 0; i <n ;i++) {
        cin >> f[i] >> tree[i+n];
    }
    long long flav = 0;
    int l = 0;
    int r = 0;
    flav += f[r];
    int sol = INT_MAX;
    build();
    while (r < n) {
        while (flav < m) {
            r++;
            if (r >= n) break;
            flav += f[r];
        }
        if (r >= n) break;
        sol = min(sol, query(l, r+1));
        flav -= f[l];
        l++;
    }
    cout << sol << endl;
}