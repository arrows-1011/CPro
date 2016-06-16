#include <bits/stdc++.h>

using namespace std;

#define INF (1<<29)

struct State {
    int c, x, y;
    
    State (int c, int x, int y) : c(c), x(x), y(y) {}

    bool operator < (const State &s) const {
        return c > s.c;
    }
};

int main()
{
    int R;
    while (cin >> R, R) {
        int W, H, sy, sx;
        vector<int> level[2];
        for (int i = 0; i < 2; i++) {
            cin >> W >> H >> sx >> sy;
            sy--; sx--;
            vector<vector<int>> a(H, vector<int>(W));
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    cin >> a[i][j];
                }
            }

            vector<vector<bool>> visited(H, vector<bool>(W, 0));
            visited[sy][sx] = 1;
            
            priority_queue<State> pq;
            pq.push(State(a[sy][sx], sx, sy));

            level[i].push_back(0);

            const int dx[] = {-1, +0, +1, +0};
            const int dy[] = {+0, -1, +0, +1};
            int maxi = 0;
            
            while (!pq.empty()) {
                State st = pq.top(); pq.pop();
                level[i].push_back(max(maxi, st.c));
                maxi = max(maxi, st.c);
                for (int j = 0; j < 4; j++) {
                    int nx = st.x + dx[j];
                    int ny = st.y + dy[j];
                    if (0 <= nx && nx < W && 0 <= ny && ny < H &&
                        !visited[ny][nx]) {
                        visited[ny][nx] = 1;
                        pq.push(State(a[ny][nx], nx, ny));
                    }
                }
            }
        }
        
        int res = INF;
        for (int i = 0; i <= R; i++) {
            int j = R - i;
            if ((int)level[0].size() <= i) continue;
            if ((int)level[1].size() <= j) continue;
            res = min(res, level[0][i] + level[1][j]);
        }
        cout << res << endl;
    }
    return 0;
}
