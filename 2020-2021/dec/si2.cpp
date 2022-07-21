#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int pre[2501][2501];
int grid[2501][2501];
int n;

bool pair2(const pii &a, const pii &b) {
    return a.second < b.second;
}

int lookup(int a1, int b1, int a2, int b2) {
    if (a1 < 0 || b1 < 0 || a2 > n || b2 > n) return 0;
    if ((a1 > 0) && (b1 > 0)) return pre[a2][b2] - pre[a1-1][b2] - pre[a2][b1-1] + pre[a1-1][b1-1];
    else if (a1 > 0) return pre[a2][b2] - pre[a1-1][b2];
    else if (b1 > 0) return pre[a2][b2] - pre[a2][b1-1];
    else return pre[a2][b2];
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    vector<pii> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    memset(grid, 0, sizeof(grid));
    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; i++) {
        cows[i].first = i;
    }
    sort(cows.begin(), cows.end(), pair2);
    for (int i = 0; i < n; i++) {
        cows[i].second = i;
        grid[cows[i].first][i] += 1;
    }
    memset(pre, 0, sizeof(pre));
    pre[0][0] = grid[0][0];
    for (int i = 1; i <= n; i++) {
        pre[i][0] = pre[i-1][0] + grid[i][0];
    }
    for (int j = 1; j <= n; j++) {
        pre[0][j] = pre[0][j-1] + grid[0][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + grid[i][j];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int x1 = min(cows[i].first, cows[j].first);
            int x2 = max(cows[i].first, cows[j].first);
            ans += (lookup(0, i, x1, j)) * (lookup(x2, i, n, j));
        }
    }
    cout << ans + 1;
}