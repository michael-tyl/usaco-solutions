#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;
int n, q;

int st[MAX_N];
int en[MAX_N];
int est[MAX_N];
int tree[MAX_N * 8];
int lcatree[MAX_N * 8];
vector<int> euler;
vector<int> e;
vector<vector<int>> adj;
int co = 0;
int tot = 0;

void dfs(int cur, int prev = -1) {
    euler.push_back(cur);
    est[cur] = tot++;
    st[cur] = co++;
    for (int nex : adj[cur]) {
        if (nex == prev) continue;
        dfs(nex, cur);
        euler.push_back(cur);
        tot++;
    }
    en[cur] = co++;
}

void update(int p, int v) {
    p += n*2;
    while (p > 0) {
        tree[p] ^= v;
        p >>= 1;
    }
}

int hig(int a, int b) {
    if (a == -1) return b;
    if (b == -1) return a;
    if (est[a] < est[b]) return a;
    return b;
}
void updatelca(int p, int v) {
    p += tot;
    lcatree[p] += v;
    p >>= 1;
    while (p > 0) {
        lcatree[p] = hig(lcatree[p<<1], lcatree[p<<1 | 1]);
        p >>= 1;
    }
}

void supdate(int p, int v) {
    p += n*2;
    tree[p] += v;
    p >>= 1;
    while (p > 0) {
        tree[p] = tree[p<<1] ^ tree[p<<1 | 1];
        p >>= 1;
    }
}

void build() {
    for (int i = 0; i < euler.size(); i++) lcatree[i+tot+1] = euler[i];
    for (int i = tot; i > 0; i--) 
        lcatree[i] = hig(lcatree[i<<1], lcatree[i<<1 | 1]);
}


int query(int l, int r) {
    int ans = 0;
    l += n*2;
    r += n*2;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans ^= tree[l++];
        if (r & 1) ans ^= tree[--r];
    }
    return ans;
}

int lcaquery(int l, int r) {
    int ans = -1;
    l += tot;
    r += tot;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = hig(ans, lcatree[l++]);
        if (r & 1) ans = hig(lcatree[--r], ans);
    }
    return ans;
}

int main() {
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    memset(lcatree, -1, sizeof(lcatree));
    cin >> n >> q;
    e.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    build();
    for (int i = 0; i < n; i++) {
        update(st[i]+1, e[i]);
        update(en[i]+1, e[i]);
    }
    for (int i = 0; i < q ;i++) {
        int form, a, b; cin >> form >> a >> b;
        if (form == 1) {
            a--;
            int dif = b - e[a];
            supdate(st[a]+1, dif);
            supdate(en[a]+1, dif);
            e[a] = b;
        } else {
            a--; b--;
            if (est[a] > est[b]) swap(a, b);
            int sol = query(1, st[a]+2) ^ query(1, st[b] + 2) ^ e[lcaquery(est[a]+1, est[b]+2)];
            cout << sol << "\n";
        }
    }
}