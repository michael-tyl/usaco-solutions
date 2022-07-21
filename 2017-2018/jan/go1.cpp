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
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<pair<int,pair<int,int>>> conn(n-1);
    for (int i = 0; i < n-1 ;i++) {
        int pi, qi, ri; cin >> pi >> qi >> ri; pi--; qi--;
        conn[i] = {ri, {pi,qi}};
    }
    vector<pair<pair<int,int>,int>> qu(q);
    for (int i = 0; i < q; i++) {
        cin >> qu[i].first.first >> qu[i].first.second;
        qu[i].second = i;
        qu[i].first.second--;
    }
    dsu d = dsu(n);
    sort(qu.begin(), qu.end());
    int cur = n - 2;
    sort(conn.begin(), conn.end());
    vector<int> ans(q);
    for (int i = q - 1; i >= 0; i--) {
        while (cur >= 0 && conn[cur].first >= qu[i].first.first) {
            d.unite(conn[cur].second.first, conn[cur].second.second);
            cur--;
        }
        ans[qu[i].second] = d.size(qu[i].first.second)-1;
    }
    for (int an : ans) {
        cout << an << "\n";
    }
}