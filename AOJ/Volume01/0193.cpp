#include <bits/stdc++.h>

using namespace std;

#define MAX 110
#define INF (1<<29)
typedef pair<int, int> pii;

int d[11][MAX][MAX]; 

int get_max_block(int M, int N,
                  vector<int> &x, vector<int> &y)
{
    int s = x.size();
    vector<int> cnt(s, 0);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int mini = INF, mid = -1, c = -1;
            for (int k = 0; k < s; k++) {
                if (d[k][i][j] < mini) {
                    mini = d[k][i][j];
                    c = 1;
                    mid = k;
                } else if (d[k][i][j] == mini) {
                    c = -1;
                }
            }
            if (c == 1) {
                cnt[mid]++;
            }
        }
    }        
    return cnt[s-1];
}

int get_dist(int sx, int sy, int gx, int gy, int M, int N)
{
    queue<pii> Q;
    Q.push(pii(sx, sy));

    vector<vector<int>> md(MAX, vector<int>(MAX, INF));
    md[sy][sx] = 0;

    const int dx[2][6] = {
        {-1, +0, -1, +1, -1, +0},
        {+0, +1, -1, +1, +0, +1}
    };
    const int dy[6] = {-1, -1, +0, +0, +1, +1};
    
    while (!Q.empty()) {
        pii p = Q.front(); Q.pop();
        int x = p.first, y = p.second;
        if (x == gx && y == gy) {
            return md[y][x];
        }

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[y&1][i];
            int ny = y + dy[i];

            if (0 <= nx && nx < M && 0 <= ny && ny < N) {
                if (md[y][x] + 1 < md[ny][nx]) {
                    md[ny][nx] = md[y][x] + 1;
                    Q.push(pii(nx, ny));
                }
            }
        }        
    }
    return INF;
}

int main()
{
    int M, N, s, t;
    while (cin >> M >> N, M) {
        cin >> s;
        vector<int> x(s), y(s);
        for (int i = 0; i < s; i++) {
            cin >> x[i] >> y[i];
            x[i]--; y[i]--;
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    d[i][j][k] = get_dist(x[i], y[i], j, k, M, N);
                }
            }
        }
        
        int res = 0;
        
        cin >> t;
        for (int i = 0; i < t; i++) {
            int X, Y;
            cin >> X >> Y;
            X--; Y--;
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    d[s][j][k] = get_dist(X, Y, j, k, M, N);
                }
            }
            x.push_back(X); y.push_back(Y);
            res = max(res, get_max_block(M, N, x, y));
            x.pop_back(); y.pop_back();
        }
        cout << res << endl;
    }
    return 0;
}
