#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    int ma = 0;
    vector<stack<int>> vst(n);
    set<int> s;
    int ma2 = 0;
    int ans = n;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; a--;
        if (flag) continue;
        if (a < ma) {
            ans = i;
            flag = true;
        }
        if (a > ma2) {
            ma2 = a;
            vst[a].push(a);
            s.insert(a);
        } else {
            auto itr = s.lower_bound(a);
            while (vst[*itr].top() < a) {
                ma = max(ma, vst[*itr].top());
                vst[*itr].pop();
            }
            vst[*itr].push(a);
        }
    }
    cout << ans << endl;
}