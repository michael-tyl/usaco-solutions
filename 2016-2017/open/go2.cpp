#include <bits/stdc++.h>

using namespace std;
const int NM = 100001;
vector<int> open(NM+1);
vector<int> last(NM+1);
vector<int> col(NM);
vector<int> coun(NM+1);
int n;
int first = -1;

int solve(int l, int r) {
    int sol = 0;
    int init = col[l];
    for (int i = l; i <= r; i++) {
        if (col[i] == 0) return 10000000;
        if (col[i] == init) continue;
        if (open[col[i]] == i) {
            sol = max(sol, solve(i, last[col[i]]) + 1);
            i = last[col[i]];
        } else {
            return 10000000;
        }
    }
    return sol;
}

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n;i++) {
        int a; cin >> a;
        col[i] = a;
        coun[a]++;
        last[a] = i;
        if (first == -1) first = a;
        if (a != first && open[a] == 0) open[a] = i;
    }
    int sol = 0;
    for (int i = 0; i < n ;i++) {
        if(col[i]==0) continue;
        if (open[col[i]] == i) {
            sol = max(sol, solve(i, last[col[i]]) + 1);
            i = last[col[i]];
        }
        else {
            sol = 10000000; break;
        }
    }
    if (sol > 1000000) cout << -1;
    else cout << sol;
    cout << endl;
}