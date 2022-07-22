#include <bits/stdc++.h>

using namespace std;
vector<long long> tot;
vector<set<int>> dadj;
vector<vector<int>> dadj2;
vector<int> c;
vector<bool> visited;
vector<int> dist;

void dfs(int cur) {
    for (int nex : dadj2[cur]) {
        if (!visited[nex]) {
            visited[nex] = true;
            dfs(nex);

        }
    }
    tot[cur] += c[cur];
    int nex = *dadj[cur].begin();
    tot[nex] += tot[cur];
}

int main() {
    freopen("shortcut.in", "r", stdin);
    freopen("shortcut.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, t; cin >> n >> m >> t;
    vector<vector<pair<int,int>>> adj(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dist.resize(n, INT_MAX);
    for (int i = 0; i < m ;i++) {
        int a, b; cin >> a >> b; a--; b--;
        int w; cin >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    priority_queue<pair<int,pair<int,int>>> pq;
    dist[0] = 0;
    visited.resize(n);
    for (auto nex : adj[0]) {
        if (nex.second <= dist[nex.first]) {
            pq.push({-nex.second, {nex.first, 0}});
            dist[nex.first] = nex.second;
        }
    }
    dadj.resize(n);
    dadj2.resize(n);
    vector<bool> done(n);
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        int cur = p.second.first;
        if (dist[cur] != INT_MAX && -p.first != dist[cur]) continue;
        dadj[cur].insert(p.second.second);
        if (done[cur]) continue;
        done[cur] = true;
        for (auto nex : adj[cur]) {
            if (-p.first+nex.second <= dist[nex.first]) {
                pq.push({p.first-nex.second, {nex.first, cur}});
                dist[nex.first] = -p.first+nex.second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dadj[i].size() > 0) dadj2[*dadj[i].begin()].push_back(i);
    }
    tot.resize(n);
    dfs(0);
    long long sol = 0;
    for (int i = 0; i < n; i++) {
        sol = max(sol, (dist[i] - t) * tot[i]);
    }
    cout << sol << endl;
}