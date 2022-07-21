#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
long long dp[101][10];
int room[101];

int main() {
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> room[i];
    }
    long long sol = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        memset(dp, 0x3F, sizeof(dp));
        // int count = 0;
        // dp[0][1] = 0;
        // for (int j = 1; j < n; j++) {
        //     count++;
        //     dp[j][1] = dp[j-1][1] + room[j]*count;
        // }
        dp[n][0] = 0;
        for (int num = 1; num <= k; num++) {
            for (int j = 0; j < n; j++) {
                int count1 = 0;
                long long total1 = 0;
                for (int l = j+1; l <= n; l++) {
                    dp[j][num] = min(dp[j][num], dp[l][num-1]+total1);
                    count1 += 1;
                    total1 += room[l]*count1;
                }
            }
        }
        sol = min(sol, dp[0][k]);
        rotate(room, room+1, room+n);
    }
    cout << sol << "\n";
}