#include <bits/stdc++.h>

using namespace std;

    //const int total = 2e8+1;
    //short prefix[total];

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    /*
    // from negative to pos
    vector<int> np;
    // from pos to neg
    vector<int> pn;
    // from pos to pos
    vector<pair<int,int>> pp;
    // from neg to neg
    vector<pair<int,int>> nn;*/
    int n;
    cin >> n;
    /*for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a <= 0 && b > 0) {
            np.push_back(b);
        } else if (a >= 0 && b < 0) {
            pn.push_back(b);
        } else if (abs(a-b) > abs(a)) {
            if (a > 0 && b > 0) {
                pp.push_back({a,b});
            } else if (a < 0 && b < 0) {
                nn.push_back({a,b});
            }
        }
    }*/

    // all coords increased by 10e8
    //int inc = 1e8;
    //memset(prefix, 0, sizeof(prefix));
    /*for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a-b) - abs(a);
        if (a <= 0 && b > 0) {
            prefix[inc] += 1;
            prefix[b+inc] -= 2;
            prefix[b*2+inc] += 1;
        } else if (a >= 0 && b < 0) {
            prefix[inc] += 1;
            prefix[b+inc] -= 2;
            prefix[b*2+inc] += 1;

        } else if (diff > 0) {
            if (a > 0 && b > 0) {
                prefix[b-diff] += 1;
                prefix[b] -= 2;
                prefix[b+diff] += 1;
            } else if (a < 0 && b < 0) {
                
                prefix[b-diff] += 1;
                prefix[b] -= 2;
                prefix[b+diff] += 1;
            }
        }
    }*/
    int inc = 1e8;
    long long dist = 0;
    map<int,int> prefix;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int diff = abs(a-b) - abs(a);
        dist += abs(a-b);
        if (a <= 0 && b > 0) {
            prefix[inc] += 1;
            prefix[b+inc] -= 2;
            prefix[b*2+inc] += 1;
        } else if (a >= 0 && b < 0) {
            prefix[inc] += 1;
            prefix[b+inc] -= 2;
            prefix[b*2+inc] += 1;

        } else if (diff > 0) {
            if (a > 0 && b > 0) {
                prefix[b-diff+inc] += 1;
                prefix[b+inc] -= 2;
                prefix[b+diff+inc] += 1;
            } else if (a < 0 && b < 0) {
                
                prefix[b-diff+inc] += 1;
                prefix[b+inc] -= 2;
                prefix[b+diff+inc] += 1;
            }
        }
    }
    long long s = 0;
    long long ad = 0;
    long long benefit = 0;
    int prev = 0;
    for (auto p : prefix) {
        s += ad * (p.first - prev);
        prev = p.first;
        ad += p.second;
        if (s > benefit) {
            benefit = s;
        }
    }
    //for (int i = 0; i < total; i++) {
    //    s += ad;
    //    ad += prefix[i];
    //    if (s > benefit) {
    //        benefit = s;
    //        sol = i;
    //    }
    //}
    cout << dist - benefit;
}