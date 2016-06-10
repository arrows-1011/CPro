#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
typedef pair<int, int> pii;
 
struct Point{
    int x,y;
};
 
int cnt[5];
int dp[5][1002];
Point cr[5][1002];
 
int getMD(const Point &p1, const Point &p2){
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
 
int main()
{
    int H, W;
    while (cin >> W >> H, W) {
	char in;    
	int sx, sy, gx, gy;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < H; i++) {
	    for (int j = 0; j < W; j++) {
		cin >> in;
		if (in == 'S') {
		    sx = j; sy = i;
		} else if (in == 'G') {
		    gx = j; gy = i;
		} else if (isdigit(in)) {
		    int n = in-'1';
		    cr[n][cnt[n]++] = (Point){j, i};
		}
	    }
	}
	for (int i = 0; i < 5; i++) { 
	    cr[i][cnt[i]++] = (Point){sx, sy};
	}
	int res = INF, num = -1;
	for (int i = 0; i < 5; i++) {
	    for (int j = 0; j < 5; j++) {
		for (int k = 0; k < cnt[j]; k++) {
		    dp[j][k] = INF;
		}
	    }
	    dp[i][cnt[i]-1] = 0;
	    int nj = i, j = (i+1) % 5, ej = (i > 0 ? i-1 : 4);
	    while (true) {
		int m = nj == i ? 0 : 1;
		for (int k = 0; k < cnt[nj]-m; k++) {
		    if (dp[nj][k] == INF) continue;
		    for (int l = 0; l < cnt[j]-m; l++) {
			dp[j][l] = min(dp[j][l], dp[nj][k]+getMD(cr[nj][k], cr[j][l]));
		    }
		}
		if (j == ej) {
		    for (int k = 0; k < cnt[j]; k++) {
			int d = dp[j][k] + getMD(cr[j][k], (Point){gx, gy});
			if (d < res) {
			    res = d;
			    num = i+1;
			}
		    }
		    break;
		}
		nj++; nj %= 5;
		j++; j %= 5;
	    }
	}
	if (res == INF) {
	    cout << "NA" << endl;
	} else {
	    cout << num << " " << res << endl;
	}
    }
    return 0;
}
