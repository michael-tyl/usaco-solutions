#include <bits/stdc++.h>

using namespace std;
int dph[22][100001];
int dpp[22][100001];
int dps[22][100001];

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k; cin >> n >> k;
    memset(dph, 0, sizeof(dph));
    memset(dpp, 0, sizeof(dpp));
    memset(dps, 0, sizeof(dps));
    char c; cin >> c;
    if (c == 'P') dpp[0][0] = 1;
    else if (c == 'H') dph[0][0] = 1;
    else dps[0][0] = 1;

    int sol = 0;
    for (int i = 1; i < n; i++) {
        char c; cin >> c;
        for (int j = 0; j <= k; j++) {
            if (c == 'P') {
                dpp[j][i] = max(dpp[j][i], dpp[j][i-1] + 1);
                // if (dph[j][i-1]) {
                    dpp[j+1][i] = max(dpp[j+1][i], dph[j][i-1] + 1);
                    dph[j][i] = max(dph[j][i], dph[j][i-1]);
                // }
                // if (dps[j][i-1]) {
                    dpp[j+1][i] = max(dpp[j+1][i], dps[j][i-1] + 1);
                    dps[j][i] = max(dps[j][i], dps[j][i-1]);
                // }
            } else if (c == 'H') {
                dph[j][i] = max(dph[j][i], dph[j][i-1] + 1);
                // if (dpp[j][i-1]) {
                    dph[j+1][i] = max(dph[j+1][i], dpp[j][i-1] + 1);
                    dpp[j][i] = max(dpp[j][i], dpp[j][i-1]);
                // }
                // if (dps[j][i-1]) {
                    dph[j+1][i] = max(dph[j+1][i], dps[j][i-1] + 1);
                    dps[j][i] = max(dps[j][i], dps[j][i-1]);
                // }
            } else {
                
                dps[j][i] = max(dps[j][i], dps[j][i-1] + 1);
                // if (dph[j][i-1]) {
                    dps[j+1][i] = max(dps[j+1][i], dph[j][i-1] + 1);
                    dph[j][i] = max(dph[j][i], dph[j][i-1]);
                // }
                // if (dpp[j][i-1]) {
                    dps[j+1][i] = max(dps[j+1][i], dpp[j][i-1] + 1);
                    dpp[j][i] = max(dpp[j][i], dpp[j][i-1]);
                // }
            }
        }
    }
    for (int j = 0; j <= k; j++) {
        sol = max(sol, dpp[j][n-1]);
        sol = max(sol, dph[j][n-1]);
        sol = max(sol, dps[j][n-1]);
    }
    cout << sol << endl;
}