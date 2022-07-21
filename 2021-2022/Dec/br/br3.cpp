#include <iostream>
#include <string.h>

using namespace std;
char grid[51][51];
//bool reachable[4][51][51];
int waysd[5][51][51];
bool down[4] = {true, false, true, false};
int waysr[5][51][51];
bool righ[4] = {false, true, false, true};

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {


        int n; int k; cin >> n >> k;
        for (int p = 0; p < n; p++) {
            for (int q = 0; q < n; q++) {
                cin >> grid[p][q];
            }
        }

        memset(waysd, 0, sizeof(waysd));
        memset(waysr, 0, sizeof(waysr));
        waysd[0][0][0] = 1;
        waysr[0][0][0] = 1;

        for (int j = 0; j <= k; j++) {
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    int wd = waysd[j][p][q];
                    if (wd > 0) {
                        if (down[j]) {
                            for (int q1 = q+1; q1 < n; q1++) {
                                if (grid[p][q1] == 'H') break;
                                waysd[j+1][p][q1] += wd;
                            }
                        } else {
                            for (int p1 = p+1; p1 < n; p1++) {
                                if (grid[p1][q] == 'H') break;
                                waysd[j+1][p1][q] += wd;
                            }
                        }
                    }
                    int wr = waysr[j][p][q];
                    if (wr > 0) {
                        if (righ[j]) {
                            for (int q1 = q+1; q1 < n; q1++) {
                                if (grid[p][q1] == 'H') break;
                                waysr[j+1][p][q1] += wr;
                            }
                        } else {
                            for (int p1 = p+1; p1 < n; p1++) {
                                if (grid[p1][q] == 'H') break;
                                waysr[j+1][p1][q] += wr;
                            }
                        }
                    }
                }
            }
        }
        long long count = 0;
        for (int j = 1; j <= k+1; j++) {
            count += waysr[j][n-1][n-1];
            count += waysd[j][n-1][n-1];
        }

        cout << count << endl;

        /*memset(reachable, false, sizeof(reachable));
        reachable[0][0][0] = true;
        for (int j = 0; j < k; j++) {
            for (int p = 0; p < n; p++) {
                for (int q = 0; q < n; q++) {
                    if (reachable[j][p][q]) {
                        for (int p1 = p; p1 < n; p1++) {

                        }
                        for (int q1 = q; q1 < n; q1++) {
                            
                        }
                    }
                }
            }
        }*/

    }
}