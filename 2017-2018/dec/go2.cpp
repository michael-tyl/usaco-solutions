#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

vector<vector<int>> e;
long long dp[100005][4];
int n, k;
vector<int> c;
long long ma;

long long solve(int cur, int col, int prev) {
    if (dp[cur][col] != ma) return dp[cur][col];
    long long count = 1;
    for (int nex : e[cur]) {
        long long cu = 0;
        if (nex == prev) continue;
        for (int i = 1; i <= 3; i++) {
            if (c[nex]) {
                if (c[nex] == col) {
                    count = 0; break;
                }
                if (i == col || i != c[nex]) continue;
                cu += solve(nex, c[nex],cur); break;
            }
            if (i == col) continue;
            cu += solve(nex, i,cur);
            cu %= MOD;
        }
        count *= cu;
        count %= MOD;
    }
    dp[cur][col] = count;
    return count;
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> k;
    e.resize(n);
    c.resize(n, 0);
    memset(dp, 127, sizeof(dp));
    ma = dp[0][0];
    for (int i = 0; i <n-1;i++) {
        int a, b; cin >> a >> b; a--;b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i = 0; i < k ;i++) {
        int x, y; cin >> x >> y; x--;
        c[x] = y;
    }
    long long sol = 0;
    if (!c[0]) sol = solve(0, 1,-1) + solve(0, 2,-1) + solve(0, 3,-1);
    else sol = solve(0, c[0],-1);
    sol %= MOD;
    cout << sol << endl;
}