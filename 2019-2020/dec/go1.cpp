#include <bits/stdc++.h>

using namespace std;
int best = 0;

vector<vector<pair<int, pair<int,int>>>> adj;
int n;

void dijk(int f) {
    vector<int> cost(n, INT_MAX);
    priority_queue<pair<int,int>> pq;
    pq.push({0,0});
    cost[0] = 0;
    while(pq.size()) {
        auto cur = pq.top();
        pq.pop();
        int cos = -cur.first;
        if (cos != cost[cur.second]) continue;
        for (auto nex : adj[cur.second]) {
            if (nex.second.second < f) continue;
            int pc = nex.second.first;
            if (cost[nex.first] > cos + pc) {
                cost[nex.first] = cos + pc;
                pq.push({-cost[nex.first], nex.first});
            }
        }
    }
    if (cost[n-1] != INT_MAX) {
        best = max(best, (1000000*f) / cost[n-1]);
    }
}

int main() {
    freopen("pump.in", "r", stdin);
    freopen("pump.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int m; cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
        pair<int,int> info = {c, d};
        adj[a].push_back({b, info});
        adj[b].push_back({a, info});
    }
    for (int f = 0; f <= 1000; f++) {
        dijk(f);
    }
    cout << best << endl;
}