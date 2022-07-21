#include <bits/stdc++.h>

using namespace std;

const int base = 1 << 17;

int tree[base << 1];
int n;
// void update(int l, int r, int v, int p = 1, int a = 0, int b = base - 1) {
//     if (l > b || r < a) return;
//     if (a >= l && b <= r) {
//         tree[p] += v;
//     } else {
//         int m = a + b;
//         m /= 2;
//         update(l, r, v, p*2, a, m);
//         update(l, r, v, p*2 + 1, m+1, b);
//         tree[p] = max(tree[p*2], tree[p*2+1]);
//     }
// }

// int query(int l, int r, int p = 1, int a = 0, int b = base - 1) {
//     if (l > b || r < a) return INT_MIN;
//     int sol = INT_MIN;
//     if (a >= l && b <= r) {
//         sol = max(sol,tree[p]);
//     } else {
//         int m = a + b;
//         m /= 2;
        
//         sol = max(query(l, r, p*2, a, m), query(l, r, p*2 + 1, m+1, b));
//     }
// }

void update(int p, int v) {
    p += n;
    tree[p] += v;
    while (p > 1) {
        tree[p>>1] = max(tree[p], tree[p^1]); 
        p >>= 1;
    }
}

int query(int l, int r) {
    int sol = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) sol = max(sol, tree[l++]);
        if (r & 1) sol = max(sol, tree[--r]);
    }
    return sol;
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int b; cin >> n >> b;
    set<int> s;
    vector<int> dep(n);
    s.insert(0);
    dep[0] = n-1;
    memset(tree, 0, sizeof(tree));
    update(0, n-1);
    vector<pair<int,int>> a(n);
    for (int i = 0; i <n ;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pair<pair<int,int>,int>> boots(b);
    for (int i = 0; i < b; i++) {
        cin >> boots[i].first.first >> boots[i].first.second;
        boots[i].second = i;
    }
    sort(a.begin(), a.end());
    sort(boots.begin(), boots.end());
    int curn = 0;
    vector<bool> ans(b);
    for (int i = 0; i < b; i++) {
        auto p = boots[i];
        int cur = p.second;
        int si = p.first.first;
        int d = p.first.second;
        while (curn < n && a[curn].first <= si) {
            int ne = a[curn].second;
            curn++;
            if (ne == 0 || ne == n-1) continue;
            auto itr = s.lower_bound(ne);
            int dist;
            if (itr == s.end()) dist = n-1;
            else dist = *itr;
            itr--;
            int prev = *itr;
            s.insert(ne);
            int dec = ne - prev -dep[prev];
            update(prev, dec);
            update(ne, dist-ne);
            dep[prev] = ne - prev;
            dep[ne] = dist-ne;
        }
        if (d >= query(0, n-1)) {
            ans[cur] = 1;
        }
    }
    for (int an : ans) {
        cout << an << "\n";
    }
}