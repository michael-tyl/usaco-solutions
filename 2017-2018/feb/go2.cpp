#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> e;
long long sol = 0;
vector<int> sizes;
vector<int> child;
long long init = 0;
vector<bool> fold;
vector<long long> ans;
vector<int> parent;

int dfs(int cur) {
    for (auto nex : e[cur]) {
        if (!fold[nex]) {child[cur]++;}
        else {child[cur] += dfs(nex);}
    }
    if (cur != 0) init += sizes[cur] * child[cur];
    return child[cur];
}

int main() {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    e = vector<vector<int>>(n);
    sizes = vector<int>(n);
    child = vector<int>(n);
    fold.resize(n);
    ans.resize(n);
    parent.resize(n);
    int filen = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        sizes[i] = s.size();
        int m; cin >> m;
        if (m == 0) {
            sol += sizes[i]; filen++; continue;
        }
        fold[i] = true;
        for (int j = 0; j < m; j++) {
            int b; cin >> b; b--;
            e[i].push_back(b);
            parent[b] = i;
        }
    }

    init = sol;    
    dfs(0);
    for (int i = 1; i < n; i++) {
        init += child[i];
    }
    stack<int> s;
    s.push(0);
    ans[0] = init;
    sol = init;
    while(s.size()) {
        int cur = s.top(); s.pop();
        if (cur != 0) {
            long long prev = ans[parent[cur]];
            prev -= (sizes[cur] + 1) * child[cur];
            prev += (filen - child[cur])*3;
            ans[cur] = prev;
            sol = min(sol, prev);
        }
        for (int nex : e[cur]) {
            if (fold[nex]) s.push(nex);
        }
    }
    cout << sol << endl;
}