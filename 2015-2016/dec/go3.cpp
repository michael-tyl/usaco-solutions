#include <bits/stdc++.h>

using namespace std;

int maze[1001][1001];
int dp[1001][1001];
int dpo[1001][1001];
int dx[] {-1, 1, 0, 0};
int dy[] {0, 0, -1, 1};

bool invalid(pair<int,int> pos, int n, int m) {
    return pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= m;
}

int main() {
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    memset(dpo, -1, sizeof(dp));
    // {bool, int} = {orange, num}
    queue<pair<pair<int,int>,pair<bool,int>>> q;
    q.push({{0,0}, {false,0}});
    while (q.size()) {
        auto nex = q.front(); q.pop();
        auto pos = nex.first;
        auto dat = nex.second;
        bool flag = false;
        if (dpo[pos.first][pos.second] != -1 && dat.second >= dpo[pos.first][pos.second]) {
            continue;
        }  
        if (dp[pos.first][pos.second] != -1 && dat.second >= dp[pos.first][pos.second]) {
            // not using right now, may be needed for tle
            flag = true;
            if (!dat.first) continue;
        }
        dp[pos.first][pos.second] = dat.second;
        if (dat.first) dpo[pos.first][pos.second] = dat.second;
        for (int d = 0; d < 4; d++) {
            pair<int,int> nexp = {pos.first + dx[d], pos.second + dy[d]};
            if (invalid(nexp, n, m)) continue;
            int nx = nexp.first, ny = nexp.second;
            // if (dp[nx][ny] != -1 && dat.second + 1 >= dp[nx][ny]) continue;
            int nt = maze[nx][ny];
            if (nt == 1) {
                q.push({nexp, {dat.first, dat.second + 1}});
            } else if (nt == 2) {
                q.push({nexp, {true, dat.second + 1}});
            } else if (nt == 3) {
                if (dat.first) q.push({nexp, {true, dat.second+1}});
            } else if (nt == 4) {
                int inc = 1;
                pair<int,int> newpos = nexp;
                while (nt == 4 && !invalid(newpos, n ,m)) {
                    newpos.first += dx[d];
                    newpos.second += dy[d];
                    nt = maze[newpos.first][newpos.second];
                    inc++;
                }
                if (invalid(newpos, n, m) || maze[newpos.first][newpos.second] == 0 || maze[newpos.first][newpos.second] == 3) {
                    newpos.first -= dx[d];
                    newpos.second -= dy[d];
                    inc--;
                }
                bool ora = false;
                if (maze[newpos.first][newpos.second] == 2) ora = true;
                q.push({newpos, {ora, dat.second + inc}});
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
}