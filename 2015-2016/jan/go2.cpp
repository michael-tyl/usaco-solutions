#include <bits/stdc++.h>

using namespace std;

long long ener(pair<int,int> f, pair<int,int> b) {
    int bx = b.first, by = b.second;
    int fx = f.first, fy = f.second;
    int dx = bx - fx;
    int dy = by - fy;
    return dx * dx + dy * dy;
}

long long dp[1005][1005];
int xd[] {1,-1,0,0};
int yd[] {0,0,1,-1};

map<char, int> dir = {
    {'E', 0},
    {'W', 1},
    {'N', 2},
    {'S', 3}
};

int main() {
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    int fx, fy, bx, by; cin >> fx >> fy >> bx >> by;
    string f, b; cin >> f >> b;
    vector<pair<int,int>> pf;
    vector<pair<int,int>> pb;
    pf.push_back({fx,fy});
    pb.push_back({bx,by});
    for (int i = 0; i < n; i++) {
        auto p = pf.back();
        pf.push_back({p.first + xd[dir[f[i]]], p.second + yd[dir[f[i]]]});
    }
    for (int i = 0; i < m; i++) {
        auto p = pb.back();
        pb.push_back({p.first + xd[dir[b[i]]], p.second + yd[dir[b[i]]]});
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         dp[i][j] = LLONG_MAX;
    //     }
    // }
    memset(dp, 127, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long e = dp[i][j];
            dp[i+1][j] = min(dp[i+1][j], e + ener(pf[i+1], pb[j]));
            dp[i+1][j+1] = min(dp[i+1][j+1], e + ener(pf[i+1], pb[j+1]));
            dp[i][j+1] = min(dp[i][j+1], e + ener(pf[i], pb[j+1]));
        }
    }
    cout << dp[n][m] << endl;
}