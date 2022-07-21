#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k; cin >> n >> k; k--;
    vector<vector<int>> e(n);
    vector<bool> visited(n);
    vector<int> num(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
        num[a]++;
        num[b]++;
    }
    queue<pair<pair<int,int>,int>> q;
    vector<int> f(n);
    q.push({{k,false},-1});
    for (int i = 0; i < n; i++) {
        if (num[i] == 1) {
            q.push({{i, true},-1});
            f[i] = 1;
        }
    }
    vector<bool> b(n);
    vector<bool> caught(n);
    b[k] = true;
    int count = 0;
    while (q.size()) {
        auto ne = q.front(); q.pop();
        auto ne1 = ne.first;
        int c = ne1.first;
        if (!ne1.second) {
            if (b[c]) {
                b[c] = false;
                if (f[c]) {
                    if (f[c] == 1) count++;
                    f[c]++;
                } else {
                    for (int nex : e[c]) {
                        if (nex == ne.second) continue;
                        q.push({{nex, false}, c});
                        b[nex] = true;
                    }
                }
            }
        } else {
            if (b[c]) {
                if (f[c] == 1) count++;
                f[c]++;
                b[c] = false;
            }
            if (visited[c]) continue;
            for (int nex : e[c]) {
                if (nex == ne.second) continue;
                q.push({{nex, true}, c});
                f[nex] = f[c];
            }
            f[c] = 0;
            visited[c] = true;
        }
    }
    cout << count << endl;
}