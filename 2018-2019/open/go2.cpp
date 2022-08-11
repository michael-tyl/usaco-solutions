#include <bits/stdc++.h>

using namespace std;

const long long MOD = 2019201997;
const long long yf = 2019201949;
const long long xf = 2019201913;

int calc(int a, int b) {
    a++; b++;
    return ((a * xf) + (b * yf)) % MOD;
}

int main() {
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n, k; cin >> n >> k;
    int co = n;
    vector<bool> used(n);
    vector<int> wei(n, INT_MAX);
    used[0] = true;
    for (int i = 1; i < n; i++) {
        wei[i] = calc(0, i);
    }
    set<int> taken;
    for (int i = 1; i < n; i++) {
        int nex;
        int miw = INT_MAX;
        for (int j = 0; j < n ;j++) {
            if (used[j]) continue;
            if (wei[j] < miw) {
                miw = wei[j];
                nex = j;
            }
        }
        used[nex] = true;
        taken.insert(-miw);
        for (int j = 1; j < n; j++) {
            int a = nex, b = j;
            if (a > b) swap(a,b);
            wei[j] = min(wei[j], calc(a, b));
        }
    }
    int cou = 1;
    for (int num : taken) {
        num = - num;
        cou++;
        if (cou == k) {
            cout << num << endl;
            break;
        }
    }
}