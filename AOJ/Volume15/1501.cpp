#include <bits/stdc++.h>

using namespace std;

constexpr int INF = (1 << 29);
constexpr int MOD = ((1e8) + 7);

int main()
{
    int r, c, x1, y1, x2, y2;
    cin >> r >> c >> y1 >> x1 >> y2 >> x2;

    vector<vector<int>> d(r, vector<int>(c, INF));
    vector<vector<int>> e(r, vector<int>(c, 0));
    d[y1][x1] = 0;
    e[y1][x1] = 1;

    constexpr int dx[] = {-1, +0, +1, +0};
    constexpr int dy[] = {+0, -1, +0, +1};
    
    queue<pair<int, int>> que;
    que.push(make_pair(y1, x1));    
    
    while (!que.empty()) {
        int x, y;
        tie(y, x) = que.front(); que.pop();

        for (int i = 0; i < 4; i++) {
            int ny = (y + dy[i] + r) % r;
            int nx = (x + dx[i] + c) % c;

            if (d[y][x] + 1 <= d[ny][nx]) {
                e[ny][nx] += e[y][x];
                e[ny][nx] %= MOD;
            }
            
            if (d[y][x] + 1 < d[ny][nx]) {
                d[ny][nx] = d[y][x] + 1;
                que.push(make_pair(ny, nx));
            }
        }        
    }
    cout << e[y2][x2] << endl;
    return 0;
}
