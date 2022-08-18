#include <bits/stdc++.h>

using namespace std;

const int MN = 5001;
const int sh = 1e6;

long long dp[MN][MN];
int match[(int)2e6+5];

int main() {
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i <n; i++) {cin >> a[i];}
    for (int i = 0; i < n; i++) {

        for (int j = i+1; j < n; j++) {
            int cur = -a[i] - a[j] + sh;
            if (cur >= 0 && cur <= 2 * sh) {
                dp[i][j] += match[cur];
            }
            match[a[j]+sh]++;
        }
        for (int j = n-1; j > i; j--) {
            match[a[j]+sh]--;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            dp[i][j] += dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
        }
    }
    for (int i = 0; i < q ;i++) {
        int a, b; cin >> a >> b; a--; b--;
        cout << dp[a][b] << "\n";
    }
}