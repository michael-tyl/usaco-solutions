#include <bits/stdc++.h>

using namespace std;

long long dp[1000001];
const long long MOD = 1e9 + 7;

long long po(long long x, long long p) {
    long long ans = 1;
    while (p > 0) {
        while (p % 2 == 0) {
            x = x * x;
            x %= MOD;
            p /= 2;
        }
        ans *= x;
        ans %= MOD;
        p--;
    }
    return ans;
}

int main() {
    freopen("spainting.in", "r", stdin);
    freopen("spainting.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, k; cin >> n >>m >> k;
    dp[0] = 0;
    for (int i = 1;i < k;i++) {
        dp[i] = dp[i-1] * m;
        dp[i] += m;
        dp[i] %= MOD;
    }
    for (int i = k; i <= n; i++) {
        dp[i] = dp[i-1] * m - dp[i-k] * (m-1);
        dp[i] %= MOD;
        dp[i] += MOD;
        dp[i] %= MOD;
    }
    long long sol = po(m, n) - dp[n] + dp[n-1];
    sol += MOD;
    sol %= MOD;
    cout << sol << endl;
}