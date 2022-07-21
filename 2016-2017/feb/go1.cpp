#include <bits/stdc++.h>

using namespace std;

long long dp[201][201][3];
int grid[201][201];
int dx[] {-1,1,0,0};
int dy[] {0,0,-1,1};

int main() {
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, t; cin >> n >> t;
    for (int i = 0; i <n ;i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, 127, sizeof(dp));
    dp[0][0][0] = 0;
    queue<pair<pair<int,int>, pair<int, long long>>> q;
    q.push({{0,0},{0,0}});
    while(q.size()) {
        auto p = q.front(); q.pop();
        auto p1 = p.first;
        int x = p1.first, y = p1.second;
        auto p2 = p.second;
        if (p2.second > dp[x][y][p2.first]) continue;
        dp[x][y][p2.first] = p2.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nn = p2.first + 1;
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            long long nex = p2.second + t;
            if (nn < 3) {
            } else {
                nex += grid[nx][ny];
                nn %= 3;
            }
            if (nex < dp[nx][ny][nn]) {
                dp[nx][ny][nn] = nex;
                q.push({{nx,ny},{nn,nex}});
            }
        }
    }
    long long sol = LLONG_MAX;
    for (int i = 0; i < 3 ;i++) {
        sol = min(sol, dp[n-1][n-1][i]);
    }
    cout << sol << endl;
}