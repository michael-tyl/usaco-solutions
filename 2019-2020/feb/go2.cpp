#include <bits/stdc++.h>

using namespace std;

const int MN = 1e5;

int pre[2*MN + 5];

const long long mod = 1e9 + 7;

long long binpow(long long x, int p) {
    long long ans = 1;
    while (p > 0) {
        while (p % 2 == 0) {
            p /= 2;
            x *= x;
            x %= mod;
        }
        ans *= x;
        ans %= mod;
        p--;
    }
    return ans;
}

int main() {
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> seg(n);
    for (int i = 0; i < n ;i++) {
        cin >> seg[i].first >> seg[i].second;
        pre[seg[i].first]++;
        pre[seg[i].second]--;
    }
    for (int i = 1; i <= 2 * n+1; i++) {
        pre[i] += pre[i-1];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += binpow(2, n - 1 - pre[seg[i].first-1]);
        ans %= mod;
    }
    cout << ans << endl;
}