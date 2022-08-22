#include <bits/stdc++.h>

using namespace std;

queue<int> q;
const int MN = 2e5 + 5;

vector<int> in[MN];
int col[MN];

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
        if (a == b) {
            return false;
        }
        if (in[a].size() < in[b].size()) {
            swap(a, b);
        }
        e[a] += e[b]; 
        e[b] = a;
        in[a].insert(end(in[a]), begin(in[b]), end(in[b]));
        if (in[a].size() > 1) {q.push(a);}
        in[b].clear();
        return true;
    }
};

int main() {
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, m; cin >> n >> m;
    dsu d = dsu(n);
    for (int i = 0; i <m ;i++) {
        int a, b; cin >> a >> b; a--; b--;
        in[a].push_back(b);
    }
    for (int i = 0; i < n; i++) {
        if (in[i].size() > 1) q.push(i);
    }
    while (q.size()) {
        int i = d.get(q.front()); 
        if (in[i].size() < 2) {q.pop(); continue;}
        int t = in[i].back();
        in[i].pop_back();
        d.unite(in[i].back(), t);
    }
    int count = 1;
    for (int i = 0; i < n; i++) {
        int rep = d.get(i);
        if (col[rep] == 0) {
            col[rep] = count++;
        }
        cout << col[rep] << "\n";
    }
}