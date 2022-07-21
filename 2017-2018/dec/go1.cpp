#include <bits/stdc++.h>

using namespace std;
int sol[200005];

int main() {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, d; cin >> n >> d;
    multiset<pair<int,int>> b;
    multiset<pair<int,int>> e;
    vector<int> bs(n);
    vector<int> es(n);
    queue<int> q;
    memset(sol, 127, sizeof(sol));
    int ma = sol[0];
    for (int i = 0; i < n ;i++) {
        int a, c; cin >> a >> c;
        b.insert({c, i});
        bs[i] = a;
        if (c == 0) {
            q.push(i);
            sol[i] = 1;
        }
    }
    for (int i = 0; i < n ;i++) {
        int a, c; cin >> a >> c;
        e.insert({a, i});
        es[i] = c;
        if (a == 0) {
            sol[i+n] = 1;
            q.push(i+n);
        }
    }
    bool flag = false;
    while (q.size()) {
        int p = q.front(); q.pop();
        int cursol = sol[p];
        if (p >= n) {
            p %= n;
            int taste = es[p];
            auto itr = b.lower_bound({taste-d, 0});
            while (itr != b.end() && itr->first <= taste) {
                int nex = itr->second;
                if (cursol + 1 < sol[nex]) {
                    sol[nex] = cursol + 1;
                    q.push(nex);
                }
                itr++;
            }
        } else {
            int taste = bs[p];
            auto itr = e.lower_bound({taste-d, 0});
            while (itr != e.end() && itr->first <= taste) {
                int nex = itr->second + n;
                if (cursol + 1 < sol[nex]) {
                    sol[nex] = cursol + 1;
                    q.push(nex);
                }
                itr++;
            }
        }
    }
    for (int i = 0; i < n ;i++) {
        if (sol[i] == ma) cout << -1 << "\n";
        else cout << sol[i] << "\n";
    }
}