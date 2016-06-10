#include <bits/stdc++.h>
 
using namespace std;

int puzzle[9][9];
 
void field(int x, int &to, int &from)
{
    if (0 <= x && x < 3) {
	to = 0;
	from = 3;
    } else if (3 <= x && x < 6) {
	to = 3;
	from = 6;
    } else {
	to = 6;
	from = 9;
    }
}
 
bool check1(int x, int y)
{
    for (int i = x-1; i >= 0; i--) {
	if (puzzle[x][y] == puzzle[i][y]) return 0;
    }
    for (int i = x+1; i < 9; i++) {
	if (puzzle[x][y] == puzzle[i][y]) return 0;
    }
    return 1;
}
 
bool check2(int x, int y)
{
    for (int i = y-1; i >= 0; i--) {
	if (puzzle[x][y] == puzzle[x][i]) return 0;
    }
    for (int i = y+1; i < 9; i++) {
	if (puzzle[x][y] == puzzle[x][i]) return 0;
    }
    return 1;
}
 
bool check3(int x, int y)
{
    int sx, tx, sy, ty;
 
    field(x, sx, tx);
    field(y, sy, ty);
    for (int i = sx; i < tx; i++) {
	for (int j = sy; j < ty; j++) {  
	    if (x == i && y == j) continue;
	    if (puzzle[x][y] == puzzle[i][j]) return 0;
	}
    }
    return 1;
}
 
int main()
{
    int T;
 
    cin >> T;
    for (int t = 0; t < T; t++) {
	if(t) cout << endl;
	for (int i = 0; i < 9; i++) {
	    for (int j = 0; j < 9; j++) {
		cin >> puzzle[i][j];
	    }
	}
 	char ch[9][9];
	for (int i = 0; i < 9; i++) {
	    for (int j = 0; j < 9; j++) {
		ch[i][j] = ' ';
	    }
	}
 	for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
		if (check1(i, j) && check2(i, j) && check3(i, j)) continue;
		ch[i][j] = '*';
	    }
	}
        for (int i = 0; i < 9; i++) {
	    for (int j = 0; j < 9; j++) {
		cout << ch[i][j] << puzzle[i][j];
	    }
	    cout << endl;
	}
    }
    return 0;
}
