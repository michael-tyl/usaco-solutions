#include <bits/stdc++.h>

using namespace std;

bool visited[21][21][4][21][21][4];
bool grid[21][21];

int dx[] {0, 1, 0, -1};
int dy[] {1, 0, -1, 0};

int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
    cin.tie(nullptr) -> sync_with_stdio(false);
    memset(visited, false, sizeof(visited));
    int n; cin >> n;
    for (int i = 0; i < n ;i++) {
        for (int j = 0; j < n ;j++) {
            char c; cin >> c;
            if (c == 'E') grid[n-1-i][j] = true;
            else grid[n-1-i][j] = false;
        }
    }
    queue<tuple<int,int,int,int,int,int>> q;
    // 0 = up, 1 = right, 2 = down, 3 = left
    q.push({0,0,0,0,0,1});
    queue<int> dist;
    dist.push(0);
    int sol = 0;
    while (q.size()) {
        auto p = q.front(); q.pop();
        int di = dist.front(); dist.pop();
        int p0, p1, p2,p3,p4,p5;
        tie(p0,p1,p2,p3,p4,p5) = p;
        if (visited[p0][p1][p2][p3][p4][p5]) {
            continue;
        }
        visited[p0][p1][p2][p3][p4][p5] = true;
        pair<int,int> ne1 = {p0 + dx[p2], p1 + dy[p2]};
        pair<int,int> ne2 = {p3 + dx[p5], p4 + dy[p5]};
        if (ne1.first < 0 || ne1.second >= n || ne1.second < 0 || ne1.first >= n || !grid[ne1.first][ne1.second]) ne1 = {p0, p1};
        if (ne2.first < 0 || ne2.first >= n || ne2.second < 0 || ne2.second >= n || !grid[ne2.first][ne2.second]) ne2 = {p3,p4};
        if (p0 == n-1 && p1 == n-1) ne1 = {p0,p1};
        if (p3 == n-1 && p4 == n-1) ne2 = {p3,p4};
        if (p0 == p1 && p1 == p3 && p3 == p4 && p4 == n-1) {
            sol = di; break;
        }
        q.push({ne1.first,ne1.second,p2,ne2.first,ne2.second,p5});
        dist.push(di+1);
        q.push({p0,p1,(p2+1)%4,p3,p4,(p5+1)%4});
        dist.push(di+1);
        q.push({p0,p1,(p2+3)%4,p3,p4,(p5+3)%4});
        dist.push(di+1);
    }
    std::cout << sol << endl;
}