#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> adj(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        adj[i]={a,b};
        total += b;
    }
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        vector<bool> visitedNow(n);
        if (visited[i]) continue;
        visited[i] = true;
        visitedNow[i] = true;
        stack<int> dfs;
        dfs.push(adj[i].first);
        int start = -1;
        while (dfs.size()) {
            int cur = dfs.top(); dfs.pop();
            if (visited[cur]) {
                if (visitedNow[cur]) start = cur;
                break;
            }
            visited[cur] = true;
            visitedNow[cur] = true;
            dfs.push(adj[cur].first);
        }
        if (start != -1) {
            stack<int> cycle;
            cycle.push(adj[start].first);
            int mi = adj[start].second;
            while (cycle.size()) {
                int cur = cycle.top(); cycle.pop();
                if (cur == start) break;
                cycle.push(adj[cur].first);
                mi = min(mi, adj[cur].second);
            }
            total -= mi;
        }
    }
    cout << total << "\n";
}