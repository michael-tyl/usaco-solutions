#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;

int tree[MAX_N];

int query(int p) {
    int ans = 0;
    while (p > 0) {
        ans += tree[p];
        p -= p & -p;
    }
    return ans;
}

void update(int p, int v) {
    while (p < MAX_N) {
        tree[p] += v;
        p += p & -p;
    }
}

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    int si = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    si++;
    update(a[n-1], 1);
    int cur = n-1;
    while (si < n && a[cur-1] < a[cur]) {
        si++;
        update(a[cur-1], 1);
        cur--;
    }
    cur = 0;
    vector<int> ord;
    while (si < n) {
        update(a[cur], 1);
        si++;
        ord.push_back(n - 1 - si + query(a[cur]));
        cur++;
    }
    cout << cur << "\n";
    for (int i = 0; i < ord.size(); i++) {
        if (i != ord.size() - 1) cout << ord[i] << " ";
        else cout << ord[i];
    }
}