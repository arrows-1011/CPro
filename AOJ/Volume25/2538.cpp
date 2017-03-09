#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_H = 50;
constexpr int MAX_W = 50;
constexpr int MAX_C = 26;
constexpr int INF = (1 << 29);

int H, W;
char C[MAX_H][MAX_W];
vector<pair<int, int>> holes[MAX_C];

int mem[MAX_H][MAX_W][MAX_H][MAX_W];
bool is_reach[MAX_H][MAX_W][MAX_H][MAX_W];

bool input()
{
    cin >> H >> W;
    
    if (H == 0 && W == 0) {
        return 0;
    }
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> C[i][j];
        }
    }
    
    return 1;
}

void init()
{
    for (int i = 0; i < MAX_C; i++) {
        holes[i].clear();
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    mem[i][j][k][l] = -1;
                    is_reach[i][j][k][l] = 0;
                }
            }
        }
    }
}

void fill()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ('A' <= C[i][j] && C[i][j] <= 'Z') {
                holes[C[i][j] - 'A'].emplace_back(j, i);
            }
        }
    }
}

bool in_field(int x, int y)
{
    return 0 <= x && x < W && 0 <= y && y < H;
}

void bfs()
{
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            is_reach[i][j][i][j] = 1;
            
            queue<pair<int, int>> Q;
            Q.push(make_pair(j, i));

            constexpr int dx[] = {0, 1};
            constexpr int dy[] = {1, 0};
            
            while (!Q.empty()) {
                int x, y;
                tie(x, y) = Q.front(); Q.pop();

                for (int k = 0; k < 2; k++) {
                    int nx = x + dx[k], ny = y + dy[k];
                    
                    if (!in_field(nx, ny) || C[ny][nx] == '#') {
                        continue;
                    }

                    if (!is_reach[i][j][ny][nx]) {
                        is_reach[i][j][ny][nx] = 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
}

int rec(int x1, int y1, int x2, int y2)
{
    int& res = mem[y1][x1][y2][x2];
        
    if (res != -1) {
        return res;
    }

    if (x1 == x2 && y1 == y2) {
        return res = 0;
    }

    if (x1 > x2 || y1 > y2) {
        return -INF;
    }
    
    constexpr int dx[] = {0, 1};
    constexpr int dy[] = {1, 0};
    
    if (C[y1][x1] != '#') {
        for (int i = 0; i < 2; i++) {
            int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
            if (in_field(nx1, ny1) && C[ny1][nx1] != '#') {
                res = max(res, rec(nx1, ny1, x2, y2));
            }            
        }
    }
    
    if (islower(C[y1][x1])) {        
        for (auto& p : holes[C[y1][x1] - 'a']) {
            int x, y;
            tie(x, y) = p;

            if (!is_reach[y1][x1][y][x] || !is_reach[y][x][y2][x2]) {
                continue;
            }

            if (abs(x1 - x) + abs(y1 - y) == 1) {                
                res = max(res, rec(x, y, x2, y2) + 1);
                continue;
            }
            
            for (int i = 0; i < 2; i++) {
                int nx1 = x1 + dx[i], ny1 = y1 + dy[i];
                for (int j = 0; j < 2; j++) {
                    int nx = x - dx[j], ny = y - dy[j];
                    
                    if (!in_field(nx, ny) || !is_reach[ny1][nx1][ny][nx]) {
                        continue;
                    }
                                        
                    res = max(res, rec(nx1, ny1, nx, ny) + rec(x, y, x2, y2) + 1);
                }
            }
            
        }
    }
         
    return res;
}

int solve()
{
    init();
    fill();
    bfs();

    if (!is_reach[0][0][H - 1][W - 1]) {
        return -1;
    }
    
    return rec(0, 0, W - 1, H - 1);    
}

int main()
{
    while (input()) {
        cout << solve() << endl;
    }
    return 0;
}
