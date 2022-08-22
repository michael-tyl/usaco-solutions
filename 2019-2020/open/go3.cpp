#include <bits/stdc++.h>

using namespace std;
long long n, m;
vector<bool> prime;

const int MN = 1e4+5;

long long dp[MN];
long long dp2[MN];

int main() {
    freopen("exercise.in", "r", stdin);
    freopen("exercise.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> m;
    prime.resize(n+1, true);
    for (long long i = 2; i * i <= n; i++) {
        for (long long j = i * i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    long long ans = 1;
    dp[0] = 1;
    dp2[0] = 1;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) continue;
        for (long long j = i; j <= n; j *= i) {
            for (int k = 0; k < n; k++) {
                if (dp[k] && k + j <= n) {
                    dp2[k+j] += dp[k] * j;
                    dp2[k+j] %= m;
                }
            }
        }
        for (int k = 1; k <= n; k++) {
            dp[k] = dp2[k];
        }
    }
    for (int k = 1; k <= n; k++) {
        ans += dp[k];
        ans %= m;
    }
    cout << ans << endl;
}