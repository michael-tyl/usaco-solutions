#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int>>> e;
vector<int> topo;
int n;

bool toposort(int x) {
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    topo.clear();
    for (int i = 0; i < x; i++) {
        for (auto p : e[i]) {
            adj[p.first].push_back(p.second);
            deg[p.second]++;
        }
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) pq.push(i);
    }
    while (pq.size()) {
        int nex = pq.top(); pq.pop();
        topo.push_back(nex);
        for (int ne : adj[nex]) {
            if (--deg[ne] == 0) pq.push(ne);
        }
    }
    if (topo.size() == n) return true;
    return false;
}

int main() {
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int m; cin >> n >> m;
    e.resize(m);
    for (int i = 0; i < m; i++) {
        int nu; cin >> nu;
        int prev = -1;
        for (int j = 0;j < nu; j++) {
            int cur; cin >> cur; cur--;
            if (prev != -1) {
                e[i].push_back({prev, cur});
            }
            prev = cur;
        }
    }
    int l = 0; int r = m;
    int mi = (l + r) / 2 +1;
    while (l < r) {
        if (toposort(mi)) {
            l = mi;
            mi = (l + r) / 2 + 1;
        } else {
            r = mi - 1;
            mi = (l + r) / 2 + 1;
        }
    }
    toposort(l);
    for (int i = 0; i < topo.size(); i++) {
        cout << topo[i]+1;
        if (i != topo.size() - 1) cout << " ";
    }
    cout << endl;
}