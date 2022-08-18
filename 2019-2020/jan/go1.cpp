#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, c; cin >> n >> m >> c;
    queue<pair<int,pair<int,int>>> bfs;
    vector<vector<int>> adj(n);
    vector<int> mo(n);
    for (int i = 0; i < n; i++) {
        cin >> mo[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }
    int ans = 0;
    bfs.push({0,{0,0}});
    while (bfs.size()) {
        auto p = bfs.front(); bfs.pop();
        int cur = p.first;
        auto inf = p.second;
        if (cur == 0) ans = max(ans, inf.first - c * inf.second * inf.second);
        if (inf.second > 1000 || inf.first < dp[cur][inf.second]) continue;
        for (int nex : adj[cur]) {
            int mon = mo[nex] + inf.first;
            if (mon > dp[nex][inf.second+1]) {
                bfs.push({nex,{mon, inf.second+1}});
                dp[nex][inf.second+1] = mon;
            }
        }
    }
    cout << ans << endl;
}