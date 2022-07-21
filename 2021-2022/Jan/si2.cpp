#include <bits/stdc++.h>

using namespace std;

struct CompP {
    
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        return a.second > b.second;
    }
};

int h[300001];
set<pair<int,int>> cur;
set<pair<int,int>, CompP> cur2;


int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    long long total = 0;
    cur.insert({h[0],0});
    cur2.insert({h[0],0});
    int si = 1;
    //long long val = 2;
    for (int i = 1; i < n; i++) {
        //total += val;
        for (auto itr = cur.begin(); itr != cur.end();) {
            auto p = *itr;
            if (p.first < h[i]) {
                total += i - p.second + 1;
                //val -= i - p.second - 1; si--;
                cur.erase(itr++);
                cur2.erase(p);
            } else {
                auto p2 = *cur2.begin();
                total += i - p2.second + 1;
                break;
            }
        }
        cur.insert({h[i],i});
        cur2.insert({h[i],i});
        si++;
        //val += si + 1;
    }
    cout << total;
}