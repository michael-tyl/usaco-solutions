#include <bits/stdc++.h>

using namespace std;
int n; 
int dist(int cur, int start) {
    if (cur >= start) return (cur - start) * (cur - start);
    else return (n + cur - start) * (n + cur - start);
}

int main() {
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    vector<int> c(n);
    vector<pair<int,bool>> ct(n, {0, true});
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ct[i].first = c[i];
    }
    for (int i = 0; i < 2 * n; i++) {
        int j = i % n;
        int jn = j + 1;
        jn %= n;
        if (ct[j].first > 1) {
            ct[jn].first += ct[j].first - 1;
            ct[jn].second = false;
            ct[j].first = 1;
        }
    }
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (ct[i].second) {start = i; break;}
    }
    int cur = start;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        start %= n;
        while (c[start]) {
            ans += dist(cur, start);
            cur++;
            cur %= n;
            c[start]--;
        }
        start++;
    }
    cout << ans << endl;
}