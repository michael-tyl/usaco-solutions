#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, p; cin >> n >> p;
    vector<pair<pair<int,int>,pair<int,int>>> b(p);
    vector<pair<pair<int,int>,pair<int,int>>> rev(p);
    for (int i = 0; i < p; i++) {
        cin >> b[i].first.first >> b[i].first.second >> b[i].second.first >> b[i].second.second;
        rev[i].first = b[i].second;
        rev[i].second = b[i].first;
    }
    sort(b.begin(), b.end());
    sort(rev.begin(), rev.end());
    map<int, int> ans;
    ans[n] = 2*n;
    int curl = p-1;
    map<pair<int,int>, int> lans;
    for (int i = p-1; i >= 0; i--) {
        while (curl >= 0 && rev[curl].first >= b[i].first) {
            lans[rev[curl].first] = ans.lower_bound(rev[curl].first.second)->second;
            curl--;
        }
        auto sp = b[i].first;
        auto la = b[i].second;
        auto itr = ans.lower_bound(la.second);
        int nex = lans[la] - la.first - la.second + sp.first + sp.second;
        if (ans.find(sp.second) != ans.end()) ans[sp.second] = min(ans[sp.second], nex);
        else ans[sp.second] = nex;
        itr = ans.lower_bound(sp.second);
        while (itr != ans.begin() && itr->second < (--itr)->second) {
            itr = ans.erase(itr);
        }
        itr = ans.lower_bound(sp.second);
        if ((++itr) != ans.end() && ans.size() > 1 && (--itr)->second > (++itr)->second) {
            itr = ans.erase(--itr);
        }
    }
    int best = 2*n;
    for (auto pa : ans) {
        best = min(best, pa.second);
    }
    cout << best << endl;
}