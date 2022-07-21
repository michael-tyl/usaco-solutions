#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int>>> e;

int main() {
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    e.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        a--; b--;
        e[a].push_back({w, b});
        e[b].push_back({w, a});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> hay(n, INT_MAX);
    vector<int> barn(n, INT_MAX);
    barn[n-1] = 0;
    for (auto p : e[n-1]) {
        pq.push(p);
        barn[p.second] = min(barn[p.second], p.first);
    }
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        int loc = p.second; int w = p.first;
        if (barn[loc] != INT_MAX && barn[loc] != w) continue;
        for (auto nex : e[loc]) {
            if (nex.first+w < barn[nex.second]) pq.push({nex.first+w, nex.second});
            barn[nex.second] = min(barn[nex.second], nex.first+w);
        }
    }
    // vector<vector<int>> hay_origin(n);
    for (int i = 0; i < k; i++) {
        int loc, y; cin >> loc >> y; loc--;
        hay[loc] = -y + barn[loc];
        for (auto nex : e[loc]) {
            pq.push({nex.first+hay[loc], nex.second});
            hay[nex.second] = min(hay[nex.second], nex.first+hay[loc]);
        }
    }
    while (pq.size()) {
        auto p = pq.top(); pq.pop();
        int loc = p.second; int w = p.first;
        if (hay[loc] != INT_MAX && hay[loc] != w) continue;
        for (auto nex : e[loc]) {
            if (nex.first+w < hay[nex.second]) {
                pq.push({nex.first+w, nex.second});
                // hay_origin[nex.second].resize(0);
            } 
            // if (nex.first+w <= hay[nex.second]) {
            //     for (int o : hay_origin[loc]) hay_origin[nex.second].push_back(o);
            // }
            hay[nex.second] = min(hay[nex.second], nex.first+w);
        }
    }
    for (int i = 0; i < n-1; i++) {
        if (hay[i] <= barn[i]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}