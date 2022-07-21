#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;
    map<pair<char,char>,bool> possible;
    // preprocessing
    for (char c1 = 'a'; c1 <= 'r'; c1++) {
        for (char c2 = c1; c2 <= 'r'; c2++) {
            int si = 0, ti = 0;
            bool poss = true;
            while (si < s.length() && ti < t.length()) {
                while (si < s.length() && s[si] != c1 && s[si] != c2) {
                    si++;
                }
                while (ti < t.length() && t[ti] != c1 && t[ti] != c2) {
                    ti++;
                }
                if (s[si] == t[ti]) {
                    si++; ti++;
                    continue;
                } else {
                    poss = false;
                    break;
                }
            }
            while (si < s.length() && s[si] != c1 && s[si] != c2) {
                si++;
            }
            while (ti < t.length() && t[ti] != c1 && t[ti] != c2) {
                ti++;
            }
            if (si < s.length() || ti < t.length()) {
                poss = false;
            }
            possible[{c1,c2}] = poss;
        }
    }
        

    // process queries
    for (int i = 0; i < q; i++) {
        string query; cin >> query;
        bool works = true;
        for (int a = 0; a < query.size(); a++) {
            for (int b = a; b < query.size(); b++) {
                if (!possible[{query[a],query[b]}]) {
                    works = false;
                }
            }
        }
        if (works) cout << 'Y';
        else cout << 'N';
    }
}