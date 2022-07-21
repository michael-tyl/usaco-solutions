#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> c(n);
    vector<vector<pair<int,int>>> e(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].first >> c[i].second;
        for (int j = 0; j < i; j++) {
            int dist = (c[i].first - c[j].first);
            dist = dist * dist;
            dist += (c[i].second - c[j].second) * (c[i].second - c[j].second);
            e[i].push_back({dist, j});
            e[j].push_back({dist, i});
        }
    }
    vector<bool> connected(n, false);
    connected[0] = true;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    for (auto p : e[0]) {
        q.push(p);
    }
    int sol = 0;
    while (q.size()) {
        auto ne = q.top();
        q.pop();
        if (connected[ne.second]) continue;
        connected[ne.second] = true;
        sol = max(sol, ne.first);
        for (auto p : e[ne.second]) {
            if (!connected[p.second]) q.push(p);
        }
    }
    cout << sol << endl;
}