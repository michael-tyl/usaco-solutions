#include <bits/stdc++.h>

using namespace std;

int dp[105][105];

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> lo(n);
    for (int i = 0; i < n ;i++) {
        cin >> lo[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][1] = dp[i-1][1];
        if (lo[i-1] == i-1) dp[i][1]++;
    }
    for (int k = 2; k <= n; k++) {
        for (int i = k; i <= n; i++) {
            int cur = dp[i-1][k-1];
            for (int j = 0; j + i <= n; j++) {
                if (lo[i+j-1] == j) cur++;
                dp[i+j][k] = max(cur, dp[i+j][k]);
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        cout << n - dp[n][k] << "\n";
    }
}