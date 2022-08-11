#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(2*n);
    int n1 = 0, n0 = 0;
    int n12 = 0, n02 = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        if (i < n && a[i] == 0) n0++;
        if (i < n && a[i] == 1) n1++;
        if (i >= n && a[i] == 0) n02++;
        if (i >= n && a[i] == 1) n12++;
    }
    long long dif = 0;
    int cur = 0;
    int l11, l01, l12=-1, l02=-1;
    for (int i = 0; i < n ;i++) {
        if (a[i] == 1) {cur++; l11 = i;}
        else {dif += cur; l01 = i;}
    }
    cur = 0;
    for (int i = n; i < 2*n ;i++) {
        if (a[i] == 1) {cur++;
            if (l12 == -1) l12 = i;
        }
        else {dif -= cur;
            if (l02 == -1) l02 = i;
        }
    }
    long long sol = abs(dif);
    long long curd = dif;
    long long cursol = 0;
    for (int i = 1; i <= min(n0, n12); i++) {
        cursol += (n-1-l01);
        curd += (n-1-l01);
        l01--;
        while(l01 >= 0 && a[l01] != 0) l01--;
        cursol += (l12-n);
        curd -= l12-n;
        l12++;
        while(l12 < 2 * n && a[l12] != 1) l12++;
        curd -= n1 - (n-n12);
        cursol++;
        sol = min(sol, cursol + abs(curd));
    }
    cursol = 0;
    curd = dif;
    for (int i = 1; i <= min(n1, n02); i++) {
        cursol += (n-1-l11);
        curd -= n-1-l11;
        l11--;
        while(l11 >= 0 && a[l11] != 1) l11--;
        cursol += (l02-n);
        curd += l02-n;
        l02++;
        while(l02 < 2 * n && a[l02] != 0) l02++;
        curd += n1 - (n-n12);
        cursol++;
        sol = min(sol, cursol + abs(curd));
    }
    cout << sol << endl;
}