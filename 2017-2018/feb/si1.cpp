#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    int l, n, rf, rb;
    cin >> l >> n >> rf >> rb;
    int diff = rf - rb;
    vector<int> taste(1000001);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j ;
        cin >> taste[j];
    }
    long long count = 0;
    long long t = 0;
    long long tas = 0;
    for (int i = l - 1; i >= 0; i--) {
        t += diff;
        if (taste[i] > tas) {
            count += t * tas;
            t = 0;
            tas = taste[i];
        }
    }
    count += t * tas;
    cout << count;
    /*set<pair<int,int>> stops;
    int tas = 0;
    for (int i = l - 1; i >= 0; i--) {
        if (taste[i] > tas) {
            tas = taste[i];
            stops.insert({i,taste[i]});
        }
    }
    int prev = 0;
    long long count = 0;
    for (auto p : stops) {
        count += (p.first - prev) * diff * p.second;
        prev = p.first;
    }
    cout << count;*/
}