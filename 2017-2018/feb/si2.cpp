#include <bits/stdc++.h>

using namespace std;
int sol = INT_MAX;
vector<pair<int,int>> boots(251);
vector<int> snow(251);
bool dp[251][251];
int n, b;

void search(int bo, int tile) {
    if (dp[bo][tile]) return;
    dp[bo][tile] = true;
    if (bo >= b) return;
    auto boo = boots[bo];
    if (tile >= n-1) sol = min(sol, bo);
    search(bo+1, tile);
    if (boo.first < snow[tile]) return;
    int cons = 0;
    for (int i = tile+1; i < n; i++) {
        if (cons >= boo.second) break;
        if (snow[i] <= boo.first) search(bo, i);
        else cons++;
    }
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
    cin >> n >> b;
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> snow[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> boots[i].first >> boots[i].second;
    }
    search(0,0);
    cout << sol;
}