#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

bool flag = false;

int counter(int cur, int prev) {
    int ch = 1;
    for (int nex : adj[cur]) {
        if (nex == prev) continue;
        ch += counter(nex, cur);
    }
    return ch;
}

int solve(int num, int cur, int prev = -1) {
    if (flag && adj[cur].size() == 2) {
        for (int nex : adj[cur]) {
            if (nex == prev) continue;
            return counter(nex, cur) % num + 1;
        }
        return 1;
    }
    else {
        multiset<int> m;
        for (int nex : adj[cur]) {
            if (nex == prev) continue;
            int t = solve(num, nex, cur);
            if (t == -1) return -1;
            if (t % num != 0) {
                auto itr = m.find(num-t);
                if (itr != m.end()) m.erase(itr);
                else m.insert(t);
            }
            
        }
        if (m.size() == 0) {
            return 1;
        } else if (m.size() == 1) {
            return (*m.begin() + 1);
        } else {
            cout << 0;
            return -1;
        }
    }
    
}
    

int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    adj.resize(n);
    vector<bool> fact(n);
    for (int i = 1; i * i <n ; i++) {
        if ((n-1) % i == 0) {fact[i] = true; fact[(n-1)/i] = true;}
    }
    int ms = 0;
    int ms2 = 0;
    int mi = 0;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        for (int j = 0; j < 2; j++) {
            int si, ind;
            if (j == 0) {
                si = adj[a].size();
                ind = a;
            } else {si = adj[b].size(); ind = b;}
            if (si > ms) {
                if (ind != mi) ms2 = ms;
                ms = si;
                mi = ind;
            } else if (si > ms2) ms2 = si;
        }
    }
    if (ms2 <= 2) flag = true;
    for (int i = 1; i < n; i++) {
        if (fact[i]) {
            int ans = solve(i, mi);
            if (ans != -1) {
                if (ans == 1) cout << 1;
                else cout << 0;
            }
        } else {
            cout << 0;
        }
    }
    cout << endl;
}