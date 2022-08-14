#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<int> par, st, en, dep;
vector<vector<int>> col;
vector<int> t;
vector<vector<pair<pair<int,int>,int>>> q;
vector<int> ans;
vector<int> curr;

int co = 0;

void dfs(int cur, int prev = -1, int depth = 0) {
    st[cur] = co;
    co++;
    par[cur] = prev;
    dep[cur] = depth;
    for (int nex : adj[cur]) {
        if (nex == prev) continue;
        dfs(nex, cur, depth+1);
    }
    en[cur] = co;
    co++;
}

void dfs2(int cur, int prev = -1) {
    col[t[cur]].push_back(cur);
    curr.push_back(cur);
    for (auto quer : q[cur]) {
        auto p = quer;
        int i = p.second;
        int b = p.first.first;
        int c = p.first.second;
        if (col[c].size() == 0) continue;
        int las = col[c].back();
        if (st[las] < st[b] && en[las] > en[b]) {
            int de = dep[las];
            if (de == curr.size()-1) continue;
            int check = curr[de+1];
            if (st[check] <= st[b] && en[check] >= en[b]) {
                continue;
            } else {
                ans[i] = 1;
            }
        } else {
            ans[i] = 1;
        }
    }
    for (int nex : adj[cur]) {
        if (nex == prev) continue;
        dfs2(nex, cur);
    }
    col[t[cur]].pop_back();
    curr.pop_back();
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    adj.resize(n);
    par.resize(n);
    st.resize(n);
    en.resize(n);
    col.resize(n);
    t.resize(n);
    q.resize(n);
    ans.resize(m);
    dep.resize(n);
    for (int i = 0; i <n ;i++) cin >> t[i];
    for (int i = 0; i <n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    for (int i = 0; i <m ;i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        q[a].push_back({{b, c},i});
        q[b].push_back({{a, c},i});
    }
    dfs2(0);
    for (int an : ans) cout << an;
    cout << endl;
}