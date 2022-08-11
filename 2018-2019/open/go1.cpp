#include <bits/stdc++.h>

using namespace std;
int dp[405][405];

int main() {
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i <n ;i++) {
        cin >> a[i];
    }
    memset(dp, 127, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    int sol = INT_MAX;
    int mat = 0;
    int sut = 0;
    for (int i = 0; i < n; i++) {
        mat = max(mat, a[i]);
        sut += a[i];
        dp[i][0] = min(dp[i][0], mat * (i + 1) - sut);
    }
    for (int kn = 0; kn < k; kn++) {
        for (int i = 0; i < n; i++) {
            int ma = 0;
            int su = 0;
            for (int j = i; j >= 0; j--) {
                ma = max(ma, a[j]);
                su += a[j];
                if (j > 0) dp[i][kn+1] = min(dp[i][kn+1], dp[j-1][kn] + ma * (i - j + 1) - su);
                else dp[i][kn+1] = min(dp[i][kn+1], ma * (i - j + 1) - su);
            }
        }
    }
    for (int kn = 0; kn <= k ; kn++) {
        sol = min(sol, dp[n-1][kn]);
    }
    cout << sol << endl;
}