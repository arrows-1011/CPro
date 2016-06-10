#include <bits/stdc++.h>
 
using namespace std;
 
const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};
 
int arr[10][10];
int ans[10][10], flip[10][10];
 
int get(int x, int y)
{
    int c = arr[x][y];
    for (int d = 0; d < 5; d++) {
	int x2 = x + dx[d], y2 = y + dy[d];
	if (0 <= x2 && x2 < 10 && 0 <= y2 && y2 < 10) {
	    c += flip[x2][y2];
	}
    }
    return c % 2;
}
 
int calc()
{
    for (int i = 1; i < 10; i++) {
	for(int j = 0; j < 10; j++) {
	    if (get(i-1, j) != 0) {
		flip[i][j] = 1;
	    }
	}
    }
 
    for (int j = 0; j < 10; j++) {
	if (get(9, j) != 0) {
	    return -1;
	}
    }
 
    int res = 0;
    for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 10; j++) {
	    res += flip[i][j];
	}
    }
    return res;
}
 
void solve()
{
    int res = -1;
 
    for (int i = 0; i < (1<<10); i++) { 
	memset(flip, 0, sizeof(flip));
	for (int j = 0; j < 10; j++) {
	    flip[0][10-j-1] = i >> j & 1;
	}
	int num = calc();
	if (num >= 0 && (res < 0 || res > num)) {
	    res = num;
	    memcpy(ans, flip, sizeof(ans));   
	}
    }
 
    for (int i = 0; i < 10; i++) {
	for (int j = 0; j < 10; j++) {
	    printf("%d%c", ans[i][j], j+1 == 10 ? '\n' : ' ');
	}
    }
}
 
int main()
{
    int Tc;
    cin >> Tc;
    while (Tc--) {
	for (int i = 0; i < 10; i++) {
	    for (int j = 0; j < 10; j++) {
		cin >> arr[i][j];
	    }
	}
	solve();
    }
    return 0;
}
