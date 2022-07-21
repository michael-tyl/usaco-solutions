#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005;
int tree[MAX_N];

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    map<int,int> count;
    vector<int> a(n);
    for (int i = 0; i < n ;i++) {
        cin >> a[i];
    }
    vector<int> o = a;
    sort(a.begin(), a.end());
    int sol = 1;
    int cur = 0;
    for (int i = 0; i< n;i ++) {
        count[a[i]]++;
        if (count[a[i]] > 0) cur++;
        count[o[i]]--;
        if (count[o[i]] >= 0) cur--;
        sol = max(sol, cur);
    }
    cout << sol << endl;
}