#include <bits/stdc++.h>

using namespace std;

struct dsu {
    vector<int> e;
    dsu(int n) {
        e = vector<int>(n, -1);
    }

    int get(int a) {
        if (e[a] < 0) return a;
        else {
            e[a] = get(e[a]);
            return e[a];
        }
    }

    bool connected(int a, int b) {
        return get(a) == get(b);
    }

    int size(int a) {
        return -e[get(a)];
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> cons(n, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    stack<int> order;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        order.push(a);
    }
    dsu d = dsu(n);
    stack<bool> ans;
    int num = 0;
    while (order.size()) {
        num++;
        int cur = order.top(); order.pop();
        cons[cur] = true;
        for (int ne : e[cur]) {
            if (cons[ne]) {
                d.unite(cur, ne);
            }
        }
        if (d.size(cur) == num) ans.push(true);
        else ans.push(false);
    }
    while (ans.size()) {
        if (ans.top()) cout << "YES";
        else cout << "NO";
        cout << "\n";
        ans.pop();
    }
}