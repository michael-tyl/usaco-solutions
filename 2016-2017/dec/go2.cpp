#include <bits/stdc++.h>

using namespace std;

int dph[1001][1001];

int dpg[1001][1001];

int dist(pair<int,int> a, pair<int,int> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int h, g;
    cin >> h >> g;
    memset(dpg, 127, sizeof(dpg));
    memset(dph, 127, sizeof(dph));
    int ma = dpg[0][0];
    vector<pair<int,int>> H(h+2);
    vector<pair<int,int>> G(g+2);
    for (int i = 0; i < h; i++) {
        cin >> H[i].first >> H[i].second;
    }
    for (int i = 0; i < g; i++) {
        cin >> G[i].first >> G[i].second;
    }
    dph[1][0] = 0;
    for (int i = 0; i <= g; i++) {
        for (int j = 1; j <= h; j++) {
            if (dpg[j][i] != ma) {
                dpg[j][i+1] = min(dpg[j][i+1], dpg[j][i] + dist(G[i-1], G[i]));
                dph[j+1][i] = min(dph[j+1][i], dpg[j][i] + dist(G[i-1], H[j]));
            }
            if (dph[j][i] != ma) {
                dpg[j][i+1] = min(dpg[j][i+1], dph[j][i] + dist(H[j-1], G[i]));
                dph[j+1][i] = min(dph[j+1][i], dph[j][i] + dist(H[j-1], H[j]));
            }
        }
    }
    cout << dph[h][g] << endl;
}