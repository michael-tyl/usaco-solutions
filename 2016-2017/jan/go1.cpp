#include <bits/stdc++.h>

using namespace std;
int n;

vector<int> tree;

void build() {
    for (int i = n - 1; i > 0; i--) {
        tree[i] = tree[i<<1] + tree[i<<1 | 1];
    }
}

void update(int p, int v) {
    p += n;
    tree[p ] += v;
    for (; p > 1; p >>= 1) {
        tree[p>>1] = tree[p] + tree[p^1];
    }
}

int query(int l, int r) {
    l += n; r+=n;
    int ans = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) ans += tree[l++];
        if (r&1) ans += tree[--r];
    }
    return ans;
}

int main() {
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    tree = vector<int>(2 * n);
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int sol = 0;
    for (int i = n - 1; i >= 0; i--) {
        int cur = a[i].second;
        int l = query(0, cur);
        int r = query(cur, n);
        if (l > 2 * r || r > 2 * l) sol++;
        update(cur, 1);
    }
    cout << sol << endl;
}