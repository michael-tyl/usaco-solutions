#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b) {
    long long count = 0;
    while (a > b) {
        if (a % 2 == 1) {
            a++; count++;
        }
        a = a >> 1; count++;
    }
    long long mult = 0;
    while (b / a >= 2) {
        a = a << 1; count++; mult++;
    }
    long long diff = b - a;
    long long max = 1 << mult;
    while (diff > 0) {
        count += diff / max;
        diff %= max;
        max = max >> 1;
    }
    return count;
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        long long ans = solve(a,b);
        long long count = 0;
        while (b > 1) {
            if (b % 2 == 1) count++;
            b = b >> 1; count++;
            ans = min(ans, solve(a,b) + count);
        }
        cout << ans << endl;
    }
}