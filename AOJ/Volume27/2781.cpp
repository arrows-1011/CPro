#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

int H, W;
char f[200][200];
 
int bfs(queue<int>& px, queue<int>& py, int gx, int gy)
{
    vector<vector<int>> d(H, vector<int>(W, INF));
    auto qx = px, qy = py;
    while (!px.empty()) {
        int x = px.front(), y = py.front();
        px.pop(); py.pop();
        d[y][x] = 0;
    }
    const int dx[] = {-1, +1, +0, +0}, dy[] = {+0, +0, -1, +1};
    while (!qx.empty()) {
        int x = qx.front(), y = qy.front();
        qx.pop(); qy.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < W && 0 <= ny && ny < H &&
                f[ny][nx]=='.') {                
                if (d[y][x] + 1 < d[ny][nx]) {
                    d[ny][nx] = d[y][x] + 1;
                    qx.push(nx); qy.push(ny);
                }
            }
        }
    }
    return d[gy][gx];
}
 
int main()
{
    int gx, gy;
    cin >> H >> W;
    queue<int> ax, ay, bx, by;
    for (int i = 0; i < H; i++) {
        for (int j = 0 ; j < W; j++) {
            cin >> f[i][j];
            if (f[i][j] == '@') {
                f[i][j] = '.';
                ax.push(j); ay.push(i);
            } else if (f[i][j] == '$') {
                f[i][j] = '.';
                bx.push(j); by.push(i);
            } else if (f[i][j] == '%') {
                f[i][j] = '.';
                gx = j; gy = i;
            }
        }
    }
    cout << (bfs(ax, ay, gx, gy) < bfs(bx, by, gx, gy) ? "Yes" : "No") << endl;
    return 0;
}
