#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
int n;

bool pair2(const pair<pii,int> &a, const pair<pii,int> &b) {
    return a.first.second < b.first.second;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n;
    vector<pair<pii,int>> east;
    vector<pair<pii,int>> north;
    vector<int> order;
    vector<int> eastC(n);
    vector<int> northC(n);
    vector<bool> northS(n);
    vector<bool> eastS(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c; int a,b; cin >> a >> b;
        if (c == 'E') {east.push_back({{a,b},i}); order.push_back(0);}
        else {north.push_back({{a,b},i}); order.push_back(1);}
    }
    sort(east.begin(), east.end(), pair2);
    sort(north.begin(), north.end());
    for (int i = 0; i < east.size(); i++) {
        auto e = east[i].first;
        for (int j = 0; j < north.size(); j++) {
            auto no = north[j].first;
            if (!northS[j] && !eastS[i] && no.first >= e.first && e.second >= no.second) {
                if (no.first - e.first > e.second - no.second) {
                    // stop east cow
                    eastS[i] = true;
                    northC[north[j].second] += eastC[east[i].second] + 1;
                    //break;
                } else if (no.first - e.first < e.second - no.second) {
                    // stop north cow
                    northS[j] = true;
                    eastC[east[i].second] += northC[north[j].second] + 1;
                    //break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (order[i]) {
            cout << northC[i] << "\n";
        } else {
            cout << eastC[i] << "\n";
        }
    }
}