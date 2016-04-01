#include <bits/stdc++.h>

using namespace std;

#define MAX_R 50
#define MAX_C 50
#define INF (1<<29)
typedef pair<int, int> pii;

bool inField(int x, int y, int C, int R)
{
    return (0 <= x && x < C && 0 <= y && y < R);
}

int main()
{
    int R, C, M;
    char field[MAX_R][MAX_C];
    cin >> R >> C >> M;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> field[i][j];
        }
    }
    int cost[3][MAX_R][MAX_C];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                cin >> cost[i][j][k];
            }
        }
    }
    vector<int> X(M), Y(M);
    for (int i = 0; i < M; i++) {
        cin >> Y[i] >> X[i];
    }

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, -1, 0, 1};
    
    map<pii, vector<int>> vis;
    int prev_d = 0;
    for (int i = 1; i < M; i++) {
        queue<pii> Q; Q.push(pii(X[i-1], Y[i-1]));
        vector<vector<int>> d(MAX_R, vector<int>(MAX_C, INF));
        vector<vector<int>> prev(MAX_R, vector<int>(MAX_C, INF));
        d[Y[i-1]][X[i-1]] = prev_d;
        while (!Q.empty()) {
            pii p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            if (x == X[i] && y == Y[i]) {
                prev_d = d[y][x];
                break;
            }
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j], ny = y + dy[j];
                if (!inField(nx, ny, C, R) ||
                    field[ny][nx] == '#') {
                    continue;
                }
                if (d[y][x] + 1 < d[ny][nx]) {
                    d[ny][nx] = d[y][x] + 1;
                    prev[ny][nx] = y*C + x;
                    Q.push(pii(nx, ny));
                }
            }
        }
        int x = X[i], y = Y[i];
        vis[pii(x, y)].push_back(d[y][x]);           
        while (x != X[i-1] || y != Y[i-1]) {           
            int nx = x, ny = y;
            nx = prev[y][x] % C;
            ny = prev[y][x] / C;
            x = nx; y = ny;
            vis[pii(x, y)].push_back(d[y][x]);           
        }
    }
    int sum = 0;
    for (auto &v : vis) {
        int x = v.first.first;
        int y = v.first.second;
        vector<int> p = v.second;
        sum += cost[1][y][x] + cost[2][y][x];
        if (p.size() > 1) {
            for (int i = 1; i < (int)p.size(); i++) {
                sum += min(cost[2][y][x] + cost[1][y][x], (p[i] - p[i-1]) * cost[0][y][x]);
            }
        }
    }
    cout << sum << endl;
    return 0;
}
