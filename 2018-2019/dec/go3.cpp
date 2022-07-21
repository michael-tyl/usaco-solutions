#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int dp[10001];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int ma = INT_MIN;
        for (int j = i; j >= 0 && i - j < k; j--) {
            ma = max(ma, s[j]);
            if (j > 0) dp[i] = max(dp[i], ma*(i-j+1)+dp[j-1]);
            else dp[i] = max(dp[i], ma*(i-j+1));
        }
    }
    cout << dp[n-1] << "\n";
}