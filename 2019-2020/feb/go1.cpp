#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> adj;
stack<int> topos;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    for (int nex : adj[cur]) {
        if (visited[nex]) continue;
        dfs(nex);
    }
    topos.push(cur);
}


int main() {
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int m, c; cin >> n >> m >> c;
    vector<int> s(n);
    for (int i = 0; i < n ;i++) {
        cin >> s[i];
    }
    adj.resize(n);
    visited.resize(n);
    vector<vector<pair<int,int>>> rev(n);
    for (int i = 0; i < c; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        adj[a].push_back(b);
        rev[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        else dfs(i);
    }
    vector<int> ord;
    while(topos.size()) {
        ord.push_back(topos.top());
        topos.pop();
    }
    vector<int> ans(n);
    for (int cur : ord) {
        int sol = s[cur];
        for (auto p : rev[cur]) {
            sol = max(sol, ans[p.first] + p.second);
        }
        ans[cur] = sol;
    }
    for (int an : ans) {
        cout << an << "\n";
    }
}