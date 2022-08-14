#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<int>> adj(m, vector<int>(m, INT_MAX/2));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m ;i++) {
            for (int j = 0; j <m ;j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    vector<int> moves;
    for (char c : s) {
        moves.push_back(c-'a');
    }
    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    for (int i = 0; i <m ; i++) {
        for (int j = 1; j <= n ;j++) {
            pre[j][i] = pre[j-1][i] + adj[moves[j-1]][i]; 
        }
    }
    vector<vector<int>> dp1(n+1, vector<int>(26, INT_MAX/2));
    vector<int> dp2(n+1, INT_MAX/2);
    dp2[0] = 0;
    for (int i = k; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp1[i][j] = min(dp2[i-k]+pre[i][j] - pre[i-k][j], dp1[i-1][j] + adj[moves[i-1]][j]);
            dp2[i] = min(dp2[i], dp1[i][j]);
        }
    }
    cout << dp2[n] << endl;
}