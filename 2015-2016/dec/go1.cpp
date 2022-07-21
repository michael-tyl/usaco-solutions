#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<bool> used(2 * n + 1, false);
    vector<int> b;
    vector<int> e1(n/2);
    vector<int> e2(n/2);
    for (int i = 0; i < n / 2; i++) {
        cin >> e1[i];
        used[e1[i]] = true;
    }
    for (int i = 0; i < n / 2; i++) {
        cin >> e2[i];
        used[e2[i]] = true;
    }
    for (int i = 0; i < 2 * n; i++) {
        if (!used[i+1]) {
            b.push_back(i+1);
        }
    }
    sort(e1.begin(), e1.end());
    sort(e2.begin(), e2.end());
    sort(b.begin(), b.end());
    int bcur = n - 1;
    int sol = 0;
    vector<bool> usedb(n, false);
    for (int i = n / 2 - 1; i >= 0; i--) {
        // while (bcur >= 0 && b[bcur] < e1[i]) {
        //     bcur--;
        // }
        // if (bcur < 0) break;
        if (b[bcur] > e1[i]) {
            sol++;
            usedb[bcur] = true;
            bcur--;
        }
        
    }
    int bcuro = bcur;
    bcur = 0;
    for (int i = 0; i < n / 2; i++) {
        // while (usedb[bcur]) bcur++;
        if (bcur > bcuro) break;
        if (b[bcur] < e2[i]) {
            sol++;
            usedb[bcur] = true;
            bcur++;
        }
        
    }
    cout << sol << endl;
}