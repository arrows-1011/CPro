#include <bits/stdc++.h>
 
using namespace std;

#define MAX 500
 
int main()
{
    int H, W;
 
    while (cin >> H >> W, H | W) {
	string s[MAX];
	int field[MAX][MAX];
 
	for (int i = 0; i < H; i++) {
	    cin >> s[i];
	    for (int j = 0; j < W; j++) { 
		if(s[i][j] == '*') {
                    field[i][j] = 0;
		} else {
		    if (j > 0) {
                        field[i][j] = field[i][j-1] + 1;
		    } else {
                        field[i][j] = 1;
                    }
                }
	    }
	}
 
	int res = 0;
	for (int i = 0; i < W; i++) {
	    for (int j = 0; j < H; j++) {
		int width = 1e9;
		for (int k = j; k < H; k++) {
		    width = min(width, field[k][i]);
		    res = max(res, (k - j + 1) * width);
		}
	    }
	}
	cout << res << endl;
    }
    return 0;
}
