#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    string s; cin >> s;
    int q; cin >> q;
    int si = s.size();
    vector<int> pc(si+1);
    vector<int> po(si+1);
    vector<int> pw(si+1);
    int cc = 0, co = 0, cw = 0;
    for (int i = 0; i < si; i++) {
        pc[i] = cc;
        po[i] = co;
        pw[i] = cw;
        if (s[i] == 'C') {
            cc++;
        } else if (s[i] == 'O') {
            co++;
        } else if (s[i] == 'W') {
            cw++;
        }
    }
    pc[si] = cc;
    po[si] = co;
    pw[si] = cw;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        int cnum = pc[b] - pc[a];
        int onum = po[b] - po[a];
        int wnum = pw[b] - pw[a];
        if ((onum - wnum) % 2 != 0) {
            cout << 'N'; continue;
        }
        cnum += (onum + wnum) / 2 + abs(onum - wnum) / 2;
        if (cnum % 2 == 1) {
            cout << 'Y'; continue;
        }
        cout << 'N';
    }
}