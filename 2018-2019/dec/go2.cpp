#include <bits/stdc++.h>
#include <array>

using namespace std;

int main() {
    freopen("cowpatibility.in", "r", stdin);
    freopen("cowpatibility.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> nums(n, vector<int>(5));
    map<array<int, 6>, int> m;
    for (int i = 0; i < n;i ++) {
        for (int j = 0; j < 5; j++) {
            cin >> nums[i][j];
        }
        sort(nums[i].begin(), nums[i].end());
        for (int k = 1; k <= 31; k++) {
            array<int, 6> cur = {0,0,0,0,0,0};
            for (int j = 0; j < 5; j ++) {
                if ((1 << j) & k) {
                    cur[cur[0]+1] = nums[i][j];
                    cur[0]++;
                }
            }
            m[cur]++;
        }
    }
    long long sol = (long long) n * (n-1) / 2;
    for (auto &p : m) {
        long long num = p.second;
        if (p.first[0] % 2) sol -= (num * (num - 1)) >> 1;
        else sol += (num * (num - 1)) >> 1;
    }
    cout << sol << endl;
}
