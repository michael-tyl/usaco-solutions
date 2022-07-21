#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

struct dsu {
    vector<int> e;
    dsu(int n) {
        e = vector<int>(n, -1);
    }

    int get(int a) {
        if (e[a] < 0) return a;
        else {
            e[a] = get(e[a]);
            return e[a];
        }
    }

    bool connected(int a, int b) {
        return get(a) == get(b);
    }

    int size(int a) {
        return -e[get(a)];
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

const int MAX = 2001;

int main() {
    freopen("fencedin.in", "r", stdin);
    freopen("fencedin.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int a, b, n, m; cin >> a >> b >> n >> m;
    // int s = (n+1) * (m+1);
    int s = MAX * MAX;
    long long ans = 0;
    dsu d = dsu(s);
    // vector<pair<int,pair<int,int>>> e;
    vector<int> vert(n+2,0), hor(m+2,0);
    vector<int> vd(n+1, 0);
    vector<int> hd(m+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> vert[i];
    }
    vert[n+1] = a;
    sort(vert.begin(), vert.end());
    for (int i = 1; i <= n; i++) {
        vd[i-1] = vert[i] - vert[i-1];
    }
    vd[n] = vert[n+1] - vert[n];
    for (int i = 1; i <= m; i++) {
        cin >> hor[i];
    }
    hor[m+1] = b;
    sort(hor.begin(), hor.end());
    for (int i = 1; i <= m; i++) {
        hd[i-1] = hor[i] - hor[i-1];
    }
    hd[m] = hor[m+1] - hor[m];
    vd.push_back(INT_MAX);
    hd.push_back(INT_MAX);
    sort(vd.begin(), vd.end());
    sort(hd.begin(), hd.end());
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         e.push_back({hd[j], {MAX * i + j, MAX * (i + 1) + j}});
    //     }
    // }
    // for (int j = 0; j < m; j++) {
    //     for (int i = 0; i <= n; i++) {
    //         e.push_back({vd[i], {MAX * i + j, MAX * i + j + 1}});
    //     }
    // }
    // sort(e.begin(), e.end());
    int i = 0;
    int j = 0;
    while (i <= n || j <= m) {
        // if (d.unite(e[i].second.first, e[i].second.second)) {
        //     ans += e[i].first;
        // }
        if (vd[i] < hd[j]) {
            for (int jtemp = 0; jtemp < m; jtemp++) {
                if (d.unite(MAX * i + jtemp, MAX * (i) + jtemp + 1)) {
                    ans += vd[i];
                }
            }
            i++;
        } else {
            for (int itemp = 0; itemp < n; itemp++) {
                if (d.unite(MAX * itemp + j, MAX * (itemp + 1) + j)) {
                    ans += hd[j];
                }
            }
            j++;
        }
    }
    cout << ans << endl;
}