#include <bits/stdc++.h>

using namespace std;

int dp[100001][2];
unordered_map<int, vector<int>> x;
unordered_map<int, vector<int>> y;
queue<pair<int,pair<int,bool>>> q;

int main() {
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, xl, yl, xb, yb; cin >> n >> xl >> yl >> xb >> yb;
    vector<pair<int,int>> f(n);
    memset(dp, 127, sizeof(dp));
    // index, {num moves, direction} (true = horizontal)
    int ma = dp[0][0];
    for (int i = 0; i <n ; i++) {
        cin >> f[i].first >> f[i].second;
        if (x.find(f[i].first) == x.end()) x[f[i].first] = vector<int>();
        if (y.find(f[i].second) == y.end()) y[f[i].second] = vector<int>();
        if (f[i].first == xl) q.push({i, {0, 0}});
        if (f[i].second == yl) q.push({i, {0, 1}});
    }
    for (int i = 0; i <n ;i++) {
        x[f[i].first].push_back(i);
        y[f[i].second].push_back(i);
    }
    int sol = INT_MAX;
    if (xl == xb || yl == yb) {
        sol = 0;
    }
    int counter = 0;
    vector<int> used(n, false);
    while (q.size()) {
        counter++;
        auto p = q.front();
        q.pop();
        auto dat = p.second;
        if (dat.first >= sol) continue;
        int ne = p.first;
        if (dat.first > dp[ne][dat.second]) continue;
        dp[ne][dat.second] = dat.first;
        if (dat.second) {
            auto vne = y[f[ne].second];
            if (f[ne].second == yb) sol = min(sol, dat.first);
            if (f[ne].first == xb) sol = min(sol, dat.first+1);
            for (int nex : vne) {
                if (nex == ne) continue;
                if (dat.first+1 >= dp[nex][0]) continue;
                if (used[nex]) continue;
                used[nex] = true;
                q.push({nex, {dat.first+1, 0}});
                dp[nex][0] = min(dp[nex][0], dat.first+1);
            }
        } else {
            if (f[ne].first == xb) sol = min(sol, dat.first);
            if (f[ne].second == yb) sol = min(sol, dat.first+1);
            auto vne = x[f[ne].first];
            for (int nex : vne) {
                if (nex == ne) continue;
                if (dat.first+1 >= dp[nex][1]) continue;
                if (used[nex]) continue;
                used[nex] = true;
                q.push({nex, {dat.first+1, 1}});
                dp[nex][1] = min(dp[nex][1], dat.first+1);
            }
        }
    }
    if (sol != INT_MAX) cout << sol << endl;
    else cout << -1 << endl;
}