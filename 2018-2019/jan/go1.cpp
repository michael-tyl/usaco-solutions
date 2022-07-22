#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long dpend[5005];
long long dp[5005];

long long binpow(long long x, long long p) {
    long long ans = 1;
    while (p > 0) {
        while (p % 2 == 0) {
            p /= 2;
            x = x * x;
            x %= MOD;
        }
        p--;
        ans *= x;
        ans %= MOD;
    }
    return ans;
}

int main() {
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> words(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b; b--;
        words[b].push_back(a);
    }
    vector<int> num(26);
    for (int i = 0; i < m; i++) {
        char c; cin >> c;
        num[c-'A']++;
    }
    dp[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            for (auto word : words[j]) {
                int prev = i - word;
                if (prev >= 0) {
                    dp[i] += dp[prev];
                    dp[i] %= MOD;
                    if (i == k) {
                        dpend[j] += dp[prev];
                        dpend[j] %= MOD;
                    }
                }
            }
        }
    }
    long long sol = 1;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (dpend[i]) flag = true;
    }

    if (flag) for (int nu : num) {
        if (nu == 0) continue;
        long long temp2 = 0;
        for (int i = 0; i < n; i++) {
            long long temp = 1;
            if (dpend[i] == 0) continue;
            temp *= binpow(dpend[i], nu);
            temp %= MOD;
            temp2 += temp;
            temp2 %= MOD;
        }
        sol *= temp2;
        sol %= MOD;
    } else sol = 0;

    cout << sol << endl;
}