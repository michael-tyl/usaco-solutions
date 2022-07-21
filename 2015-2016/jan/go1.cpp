#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        x.push_back(a);
    }
    sort(x.begin(), x.end());
    vector<pair<int,int>> dpl(n);
    vector<pair<int,int>> dpr(n);
    dpl[0] = {x[0], 0};
    for (int i = 1; i < n; i++) {
        int p = dpl[i-1].second;
        int d = dpl[i-1].first;
        if (x[i] - dpl[i-1].first > p) {p++; d = x[i-1];}
        if (x[i] - x[i-1] > p) {
            p = x[i] - x[i-1];
            d = x[i-1];
        }
        dpl[i] = {d, p};
    }
    dpr[n-1] = {x[n-1], 0};
    for (int i = n - 2; i >= 0; i--) {
        int p = dpr[i+1].second;
        int d = dpr[i+1].first;
        if (dpr[i+1].first - x[i] > p) {p++; d = x[i+1];}
        if (x[i+1] - x[i] > p) {
            p = x[i+1] - x[i];
            d = x[i+1];
        }
        p = max(p, x[i+1] - x[i]);
        dpr[i] = {d, p};
    }
    int sol = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        int l = dpl[i].second;
        int r = dpr[i+1].second;
        int p = max(l, r);
        int d = x[i+1] - x[i];
        int d2 = dpr[i+1].first - dpl[i].first;
        if (l > r) {
            d2 = x[i+1] - dpl[i].first;
        } else if (r > l) {
            d2 = dpr[i+1].first - x[i];
        }
        if (d2 > p) p++;
        p *= 2;
        p = max(p, d);
        sol = min(p, sol);
    }
    for (int i = 0; i < n - 2; i++) {
        int l = dpl[i].second;
        int r = dpr[i+2].second;
        int p = max(l, r);
        int d = x[i+2] - x[i];
        int d2 = dpr[i+2].first - dpl[i].first;
        if (l > r) {
            d2 = x[i+2] - dpl[i].first;
        } else if (r > l) {
            d2 = dpr[i+2].first - x[i];
        }
        if (d2 > p) p++;
        p *= 2;
        p = max(p, d);
        sol = min(p, sol);
    }
    for (int i = 0; i < n; i++) {
        sol = min(sol, 2*max(dpl[i].second, dpr[i].second));
    }
    cout << sol / 2 << "." << (sol % 2 ? 5 : 0);
}