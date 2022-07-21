#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

vector<vector<int>> adj(100001);

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<int> dfs;
    dfs.push(0);
    long long sol = 0;
    vector<bool> visited(n);
    visited[0] = true;
    while (dfs.size()) {
        int cur = dfs.top(); dfs.pop();
        int num = 0;
        for (int next : adj[cur]) if (!visited[next]) {
            dfs.push(next);
            visited[next] = true;
            num++;
            sol++;
        }
        int diff = 1;
        while (num > 0) {
            num -= diff;
            diff = diff << 1;
            sol++;
        }
    }
    cout << sol;
}