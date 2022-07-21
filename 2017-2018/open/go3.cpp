#include <bits/stdc++.h>

using namespace std;
int dp[1005];

int main() {
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, w; cin >> n >> w;
    vector<pair<double,pair<int,int>>> c(n);
    for (int i = 0; i < n;i ++) {
        cin >> c[i].second.second >> c[i].second.first;
        c[i].first = (double) -c[i].second.first / c[i].second.second;
    }
    sort(c.begin(), c.end());
    double sol = 0;
    for (int i = 0; i < n ;i++) {
        int cw = c[i].second.second;
        int ct = c[i].second.first;
        for (int j = w-1; j >= 0; j--) {
            if (j > 0 && dp[j] == 0) continue;
            int nex = dp[j] + ct;
            int wei = j + cw;
            if (wei >= w) {
                sol = max(sol, (double) nex / wei);
            } else {
                dp[wei] = max(dp[wei], nex);
            }
        }
    }
    cout << (int) (sol * 1000) << endl;
}