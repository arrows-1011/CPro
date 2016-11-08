#include <iostream>
  
using namespace std;
  
bool flg;
  
void init(char field[8][8], bool can[8][8])
{
    flg = false;
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    field[i][j] = '.';
	    can[i][j] = true;
	}
    }
}
  
bool in_field(int y, int x)
{
    return (0 <= y && y < 8 && 0 <= x && x < 8);
}
  
void putQ(int r, int c, bool can[8][8])
{
    constexpr int dx[4] = {-1, +1, +1, -1};
    constexpr int dy[4] = {-1, -1, +1, +1};
    
    for (int i = 0; i < 8; i++) {
	can[r][i] = can[i][c] = false;
    }
    for (int i = 0; i < 4; i++) {
	int x = c, y = r;
	while (in_field(y, x)) {
	    can[y][x] = false;
	    x += dx[i]; y += dy[i];
	}
    }
}
  
void print(char field[8][8])
{
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    cout << field[i][j];
	}
	cout << endl;
    }
}
  
void copy(bool a[8][8], bool b[8][8])
{
    for (int i = 0; i < 8; i++) {
	for (int j = 0; j < 8; j++) {
	    a[i][j] = b[i][j];
	}
    }
}
  
void solve(int now, int S, bool can[8][8], char field[8][8])
{
    if (now == 8) {
	print(field);
	flg = true;
	return;
    }
    if ((S >> now) & 1) {
	solve(now + 1, S, can, field);
    } else {
	bool tmp[8][8];
	for (int i = 0; i < 8; i++) {
	    if (can[now][i]) {
		copy(tmp, can);
		field[now][i] = 'Q';
		putQ(now, i, can);
		solve(now + 1, S, can, field);
		if (flg) return;
		copy(can, tmp);
		field[now][i] = '.';
	    }
	}
    }
}
  
int main()
{
    int N, r, c, S = 0;
    bool can[8][8];
    char field[8][8];
  
    init(field, can);
  
    cin >> N;
    for (int i = 0; i < N; i++) {
	cin >> r >> c;
	S |= 1 << r;
	field[r][c] = 'Q';
	putQ(r, c, can);
    }
    solve(0, S, can, field);
    return 0;
}
