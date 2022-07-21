#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
vector<int> t;
vector<int> change;
vector<int> deriv;
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        p.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        t.push_back(a);
    }
    change.push_back(t[0] - p[0]);
    for (int i = 1; i < n; i++) {
        int num = t[i] - p[i];
        if (change[change.size() - 1] != num) {
            change.push_back(num);
        };
    }
    long long count = 0;

    // NEW LOCAL N HERE
    int n = change.size();

    int prev = 0;
    for (int i = 0; i < n; i++) {
        int cur = change[i];
        if (prev == 0) {
            count += abs(cur);
        } else if (cur != 0) {
            if (prev > 0 && cur > 0 || prev < 0 && cur < 0) {
                if (abs(prev) < abs(cur)) {
                    count += abs(cur) - abs(prev);
                }
            } else {
                count += abs(cur);
            }
        }
        prev = cur;
    }
    
    cout << count;
}