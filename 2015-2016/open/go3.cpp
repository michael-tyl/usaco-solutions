#include <bits/stdc++.h>

using namespace std;

int dp[250][250];

int main() {
    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <n ;i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }
    int sol = 0;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i + k < n; i++) {
            for (int j = i; j < i + k; j++) {
                if (dp[i][j] == dp[j+1][i+k]) {
                    dp[i][i+k] = max(dp[i][i+k], dp[i][j] + 1);
                    sol = max (sol, dp[i][i+k]);
                }
            }
        }
    }
    cout << sol << endl;
}