#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 101
 
int H, W, sx, sy, gx, gy;
int color, dir, field[MAX][MAX];
 
struct P {
    int x, y;
    P(int x, int y) : x(x), y(y) {}
};
 
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
 
bool check(int y, int x)
{
    if (0 <= y && y < H && 0 <= x && x < W) {
	return true;
    }
    return false;
}
 
void paint(int y, int x)
{
    if (!dir) {
	for (int i = 0; i < 2; i++) {
	    for (int j = 0; j < 4; j++) {
		field[y+i][x+j] = color;
	    }
	}
    } else {
	for (int i = 0; i < 4; i++) {
	    for (int j = 0; j < 2; j++) {
		field[y+i][x+j] = color;
	    }
	}
    }
}
 
bool bfs()
{
    bool used[MAX][MAX];
    memset(used, false, sizeof(used));
    used[sy][sx] = true;
 
    queue<P> Q;
    Q.push(P(sx, sy));
 
    while (!Q.empty()) {
	P p = Q.front(); Q.pop();
 
	if (field[p.y][p.x] == -1) continue;
 
	for (int i = 0; i < 4; i++) {
	    int nx = p.x + dx[i];
	    int ny = p.y + dy[i];
 
	    if (!check(ny, nx) || used[ny][nx] || 
	       field[p.y][p.x] != field[ny][nx]) continue;
 
	    used[ny][nx] = true;
	    Q.push(P(nx, ny));     
	}
    }
    return used[gy][gx];
}
 
int main()
{
    int n, x, y;
    while (cin >> W >> H, (W | H)) {
	memset(field, -1, sizeof(field));
 
	cin >> sx >> sy >> gx >> gy >> n;
	sy--, sx--, gy--, gx--;
 
	for (int i = 0; i < n; i++) {
	    cin >> color >> dir >> x >> y;
	    y--, x--;
	    paint(y, x);
	}
	cout << (bfs() ? "OK" : "NG") << endl;
    }
    return 0;
}
