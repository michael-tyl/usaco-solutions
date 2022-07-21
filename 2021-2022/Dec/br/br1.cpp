#include <iostream>
#include <vector>

using namespace std;

vector<char> cows;

int main() {
    int n; cin >> n;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        cows.push_back(c);
    }
    long long count = 0;
    if (cows[0] != cows[1]) {
        for (int i = 2; i < n; i++) {
            if (cows[i] == cows[0]) break;
            count++;
        }
    }
    if (cows[n-1] != cows[n-2]) {
        for (int i = n-3; i >= 0; i--) {
            if (cows[i] == cows[n-1]) break;
            count++;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        char cur = cows[i];
        long long r = 1;
        long long l = 1;
        if (i < n - 1 && cur != cows[i+1]) {
            r++;
            for (int j = i + 2; j < n; j++) {
                if (cur != cows[j]) r++;
                else break;
            }
            //if (i > 0 && cur != cows[i-1]) count += 1 + c1;
        }
        
        if (i > 0 && cur != cows[i-1]) {
            l++;
            for (int j = i - 2; j >= 0; j--) {
                if (cur != cows[j]) l += 1;
                else break;
            }
        }
        int over = 3;
        if (r >= 3 && l == 1 || r == 1 && l >= 3) over = 2;
        long long prod = r * l - over;
        if (prod > 0) count += prod;
    }
    cout << count;
}