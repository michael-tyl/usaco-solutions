#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int t, a, b; cin >> t >> a >> b;
    vector<bool> dp(t+1, false);
    dp[0] = true;
    int ma = 0;
    vector<bool> dp2(t+1, false);
    for (int i = 0; i <= t; i++) {
        if (dp[i]) {
            if (i + a <= t) dp[i + a] = true;
            if (i + b <= t) dp[i+b] = true;
            dp2[i/2] = true;
            ma = max(ma, i);
        }
    }
    for (int i = 0; i <= t; i++) {
        if (dp2[i]) {
            if (i + a <= t) dp2[i + a] = true;
            if (i + b <= t) dp2[i+b] = true;
            ma = max(ma, i);
        }
    }
    cout << ma << endl;
}