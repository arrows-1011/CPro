#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct State {
    int x, y, dir, n;
    State(int x, int y, int dir, int n)
        : x{x}, y{y}, dir{dir}, n{n} {}
};

int H, W;
string commands;
vector<vector<char>> field;
vector<int> dir[4];
constexpr int dx[4] = {-1, +0, +1, +0};
constexpr int dy[4] = {+0, -1, +0, +1};

bool in_field(int x, int y)
{
    return (0 <= x && x < W && 0 <= y && y < H);
}

void init()
{
    for (int i = 0; i < 4; i++) {
        dir[i].clear();
    }
}

void make(int N)
{
    init();
    int nd = 1;
    for (int i = 0; i < N; i++) {
        if (commands[i] == 'L') {
            nd = (nd + 3) % 4;
        } else {
            nd = (nd + 1) % 4;
        }
        dir[nd].emplace_back(i);
    }    
}

bool solve(int sx, int sy, int gx, int gy)
{
    queue<State> Q;
    Q.push({sx, sy, 1, 0});
    
    bool d[H][W][4];
    memset(d, 0, sizeof(d));
    d[sy][sx][1] = 1;

    while (!Q.empty()) {
        State s = Q.front(); Q.pop();
        int x = s.x, y = s.y;
        if (x == gx && y == gy) return 1;
        
        // move forward
        int nx = s.x + dx[s.dir], ny = s.y + dy[s.dir];
        if (in_field(nx, ny) && field[ny][nx] != '#' && !d[ny][nx][s.dir]) {
            d[ny][nx][s.dir] = 1;
            Q.push({nx, ny, s.dir, s.n});
        }
        
        // turn
        for (int i = 0; i < 4; i++) {
            if (i == s.dir) continue;
            
            auto np = lower_bound(dir[i].begin(), dir[i].end(), s.n);
            if (np == dir[i].end()) continue;
            int nn = np - dir[i].begin();
            if (!d[y][x][i]) {
                d[y][x][i] = 1;
                Q.push({x, y, i, nn + 1});                
            }
        }
    }    
    return 0;
}

int main()
{
    int N, sx, sy, gx, gy;
    while (cin >> H >> W >> N, H) {
        cin >> commands;
        field.resize(H);
        for (int i = 0; i < H; i++) {
            field[i].resize(W);
            for (int j = 0; j < W; j++) {
                cin >> field[i][j];
                if (field[i][j] == 'S') { 
                    field[i][j] = '.';
                    sx = j; sy = i;
                } else if (field[i][j] == 'G') {
                    field[i][j] = '.';
                    gx = j; gy = i;
                }
            }
        }
        make(N);
        cout << (solve(sx, sy, gx, gy) ? "Yes" : "No") << endl;
    }
    return 0;
}
