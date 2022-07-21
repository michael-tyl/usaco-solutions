#include <bits/stdc++.h>

using namespace std;
string s;

typedef pair<int,int> pii;

int orientation(pii p1, pii p2, pii p3) {
   long long val = ((long long)p2.second - p1.second) * (p3.first - p2.first) -
      (p2.first - p1.first) * (p3.second - p2.second);

   if (val == 0) return 0;  // colinear 

   return (val > 0) ? 1 : 2; // clock or counterclock wise 
}

int main() {
    freopen("lightsout.in", "r", stdin);
    freopen("lightsout.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    vector<int> e(n);
    vector<int> dist(n, INT_MAX);
    vector<int> o(n);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        int ne = i + 1; ne %= n;
        int pr = i - 1; pr += n; pr %= n;
        o[i] = -1 * orientation(v[pr], v[i], v[ne]);
        e[i] = abs(v[ne].first - v[i].first + v[ne].second - v[i].second);
        dist[i] = min(dist[i], dist[pr] + e[pr]);
    }
    for (int i = n-1; i > 0; i--) {
        int ne = i + 1; ne %= n;
        int pr = i - 1; pr += n; pr %= n;
        dist[i] = min(dist[i], dist[ne] + e[i]);
    }
    o[0] = 0;
    multiset<vector<int>> se;
    vector<int> all;
    for (int i = 0; i < n; i++) {
        all.push_back(o[i]);
        all.push_back(e[i]);
    }
    all.push_back(0);
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = 0; j + i <= n; j++) {
            se.insert(vector<int>(all.begin() + 2 * i, all.begin() + 2 * (i + j) + 1));
        }
    }
    int sol = 0;
    for (int i = 1; i < n; i++) {
        int di = 0;
        vector<int> cur;
        cur.push_back(o[i]);
        for (int j = i + 1; j < n; j++) {
            cur.push_back(e[j-1]);
            cur.push_back(o[j]);
            di += e[j-1];
            if (se.count(cur) == 1) {
                sol = max(sol, (di + dist[j])-dist[i]);
                break;
            }
        }
    }
    cout << sol << endl;
}