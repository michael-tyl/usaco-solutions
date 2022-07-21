#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int main() {
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i< n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i< n;i++) {
        cin >> b[i];
    }
    memset(dp, 0, sizeof(dp));
    int sol = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            if (abs(a[i] - b[j]) <= 4) {
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                sol = max(sol, dp[i+1][j+1]);
            }
        }
    }
    cout << sol << endl;
}