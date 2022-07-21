#include <bits/stdc++.h>

using namespace std;

int n;

void build(vector<int> &tree) {
    for (int i = n - 1; i >= 0; i--) {
        tree[i] = min(tree[i<<1], tree[(i<<1) + 1]);
    }
}

int query(vector<int> &tree, int l, int r) {
    int ans = INT_MAX;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = min(ans, tree[l++]);
        if (r & 1) ans = min(ans, tree[--r]);
    }
    return ans;
}

void buildm(vector<int> &tree) {
    for (int i = n - 1; i >= 0; i--) {
        tree[i] = max(tree[i<<1], tree[(i<<1) + 1]);
    }
}

int querym(vector<int> &tree, int l, int r) {
    int ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, tree[l++]);
        if (r & 1) ans = max(ans, tree[--r]);
    }
    return ans;
}

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    vector<pair<int,int>> cx(n);
    vector<pair<int,int>> cy(n);
    for (int i = 0; i < n; i++) {
        cin >> cx[i].first >> cx[i].second;
        cy[i].first = cx[i].second;
        cy[i].second = cx[i].first;
    }
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    vector<int> xt(2*n);
    vector<int> yt(2*n);
    vector<int> xtm(2*n);
    vector<int> ytm(2*n);
    for (int i = n; i < 2 * n; i++) {
        xt[i] = cy[i-n].second;
        yt[i] = cx[i-n].second;
        xtm[i] = cy[i-n].second;
        ytm[i] = cx[i-n].second;
    }
    build(xt);
    build(yt);
    buildm(xtm);
    buildm(ytm);
    long long orig = (long long)(querym(xtm, 0, n) - query(xt, 0, n)) * (querym(ytm, 0 ,n) - query(yt, 0, n));
    long long saved = 0;
    for (int i = 0; i <n-1 ;i++) {
        // i is the last one in first enclosure
        long long area =  ((long long)querym(xtm, 0, i+1) - query(xt, 0, i+1)) * (cy[i].first - cy[0].first);
        area +=  ((long long)querym(xtm, i+1, n) - query(xt, i+1, n)) * (cy[n-1].first - cy[i+1].first);
        saved = max(saved, orig - area);
        
        area =  ((long long)querym(ytm, 0, i+1) - query(yt, 0, i+1)) * (cx[i].first - cx[0].first);
        area +=  ((long long)querym(ytm, i+1, n) - query(yt, i+1, n)) * (cx[n-1].first - cx[i+1].first);
        saved = max(saved, orig - area);
    }
    cout << saved << endl;
}