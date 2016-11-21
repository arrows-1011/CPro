#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAX_H = 16;
constexpr int MAX_W = 16;
constexpr int dx[5] = {-1, +0, +1, +0, +0};
constexpr int dy[5] = {+0, -1, +0, +1, +0};

int W, H, N;

inline bool reach(const vector<int>& sx, const vector<int>& sy,
           const vector<int>& gx, const vector<int>& gy)
{
    for (int i = 0; i < N; i++) {
        if (sx[i] != gx[i] || sy[i] != gy[i]) {
            return 0;
        }
    }
    return 1;
}

inline bool same(int& x1, int& y1, int& x2, int& y2)
{
    return (x1 == x2 && y1 == y2);
}

bool d[MAX_H][MAX_W][MAX_H][MAX_W][MAX_H][MAX_W];

int bfs(const vector<string>& field,
        const vector<int>& sx, const vector<int>& sy,
        const vector<int>& gx, const vector<int>& gy)
{
    queue<pair<vector<int>, vector<int>>> que;
    queue<int> qc;
    
    que.push(make_pair(sx, sy));    
    qc.push(0);
    
    memset(d, 0, sizeof(d));
    d[sy[0]][sx[0]][sy[1]][sx[1]][sy[2]][sx[2]] = 1;

    while (!que.empty()) {
        auto f = que.front(); que.pop();
        int c = qc.front(); qc.pop();
        auto& cx = f.first;
        auto& cy = f.second;
        
        if (reach(cx, cy, gx, gy)) return c;
                
        for (int i = 0; i < 5; i++) {            
            int nx0 = cx[0] + dx[i], ny0 = cy[0] + dy[i];            
            
            if (field[ny0][nx0] == '#') continue;
            if (N == 1) {
                if (!d[ny0][nx0][cy[1]][cx[1]][cy[2]][cx[2]]) {
                    d[ny0][nx0][cy[1]][cx[1]][cy[2]][cx[2]] = 1;
                    
                    vector<int> nx = {nx0, cx[1], cx[2]}, ny = {ny0, cy[1], cy[2]};                     
                    que.push(make_pair(nx, ny));                    
                    qc.push(c + 1);
                }
                continue;
            }
            
            for (int j = 0; j < 5; j++) {                
                int nx1 = cx[1] + dx[j], ny1 = cy[1] + dy[j];
                if (field[ny1][nx1] == '#') continue;
                if (same(nx0, ny0, nx1, ny1)) continue;
                if (same(nx0, ny0, cx[1], cy[1]) && same(cx[0], cy[0], nx1, ny1)) continue;                
                
                if (N == 2) {
                    if (!d[ny0][nx0][ny1][nx1][cy[2]][cx[2]]) {
                        d[ny0][nx0][ny1][nx1][cy[2]][cx[2]] = 1;
                        
                        vector<int> nx = {nx0, nx1, cx[2]}, ny = {ny0, ny1, cy[2]};                     
                        que.push(make_pair(nx, ny));                    
                        qc.push(c + 1);
                    }   
                    continue;
                }
                
                for (int k = 0; k < 5; k++) {
                    int nx2 = cx[2] + dx[k], ny2 = cy[2] + dy[k];
                    
                    if (field[ny2][nx2] == '#') continue;
                    if (same(nx0, ny0, nx2, ny2) || same(nx1, ny1, nx2, ny2)) continue;
                    if (same(nx0, ny0, cx[2], cy[2]) && same(cx[0], cy[0], nx2, ny2)) continue;                
                    if (same(nx1, ny1, cx[2], cy[2]) && same(cx[1], cy[1], nx2, ny2)) continue;                

                    if (!d[ny0][nx0][ny1][nx1][ny2][nx2]) {
                        d[ny0][nx0][ny1][nx1][ny2][nx2] = 1;
                        vector<int> nx = {nx0, nx1, nx2}, ny = {ny0, ny1, ny2};                     
                        que.push(make_pair(nx, ny));
                        qc.push(c + 1);
                    }
                }
            }
        }      
    }    
    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while (cin >> W >> H >> N, W > 0) {
        vector<string> field(H);
        vector<int> sx(N), sy(N), gx(N), gy(N);
        cin.ignore();
        for (int i = 0; i < H; i++) {
            getline(cin, field[i]);
            for (int j = 0; j < W; j++) {
                if (field[i][j] == ' ') {
                    field[i][j] = '.';
                } else if (islower(field[i][j])) {
                    sx[field[i][j] - 'a'] = j;
                    sy[field[i][j] - 'a'] = i;
                    field[i][j] = '.';
                } else if (isupper(field[i][j])) {
                    gx[field[i][j] - 'A'] = j;
                    gy[field[i][j] - 'A'] = i;
                    field[i][j] = '.';
                }
            }
        }

        while (sx.size() < 3) {
            sx.emplace_back(0);
            sy.emplace_back(0);
            gx.emplace_back(0);
            gy.emplace_back(0);
        }
        cout << bfs(field, sx, sy, gx, gy) << endl; 
    }
    return 0;
}
