#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

using Mat = vector<vector<char>>;

constexpr char col[] = {'R', 'G', 'B'};
constexpr int MAX = 10;

constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, -1, 0, 1};

int W, H;
Mat M;

bool visited[MAX][MAX];

bool in_field(int x, int y)
{
    return (0 <= x && x < W && 0 <= y && y < H);
}

void paint(Mat& m, int x, int y, char nc, char c)
{
    if (visited[y][x]) return;
    visited[y][x] = 1;

    m[y][x] = nc;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (in_field(nx, ny) && m[ny][nx] == c) {
            paint(m, nx, ny, nc, c);
        }
    }
}

Mat get_next(const Mat& m, char c)
{
    Mat res = m;
    memset(visited, 0, sizeof(visited));
    paint(res, 0, 0, c, m[0][0]);
    return res;
}

bool reach(Mat& m)
{
    char c = m[0][0];
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (m[i][j] != c) {
                return 0;
            }
        }
    }
    return 1;
}

int bfs()
{
    queue<Mat> Q;
    Q.push(M);

    map<Mat, int> d;
    d[M] = 0;
    
    while (!Q.empty()) {
        Mat m = Q.front(); Q.pop();

        if (reach(m)) return d[m];
        
        for (int i = 0; i < 3; i++) {
            if (m[0][0] == col[i]) continue;
            Mat next = get_next(m, col[i]);
            if (d.count(next) == 0) {
                d[next] = d[m] + 1;
                Q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    while (cin >> W >> H, W > 0) {
        M.resize(H);
        for (int i = 0; i < H; i++) {
            M[i].resize(W);
            for (int j = 0; j < W; j++) {
                cin >> M[i][j];
            }
        }
        cout << bfs() << endl;
    }        
    return 0;
}
