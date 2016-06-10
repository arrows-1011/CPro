#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
int field[5000][5],tmp[5000][5];
 
void down()
{
    memset(tmp, 0, sizeof(tmp));
    for (int j = 0; j < 5; j++) {
	int p = 4999;
	for (int i = 4999; i >= 0; i--) {
	    if (field[i][j] == -1) continue;
	    tmp[p--][j] = field[i][j];
	}
    }
    for (int i = 0; i < 5000; i++) {
	for (int j = 0; j < 5; j++) {
	    field[i][j] = tmp[i][j];
	}
    }
}
 
void remove()
{
    bool flg = false;
    for (int i = 0; i < 5000; i++) {
	int cnt = 0;
	for (int j = 0; j < 5; j++, cnt++) {
	    if (!field[i][j]) break;
	}
	if (cnt == 5) {
	    flg = true;
	    for (int j = 0; j < 5; j++) {
		field[i][j] = -1;
	    }
	}
    }
   
    if (flg) {
	down();
    }
}
 
int main()
{
    int N, d, p, q;
 
    while (cin >> N, N) {
	memset(field, 0, sizeof(field));
	for (int i = 0; i < N; i++) {
	    cin >> d >> p >> q; q--;
	    if (d == 1) {
		int min = INF;
		for (int j = q; j < p+q; j++) {
		    for (int i = 0; i < 5000; i++) {
			if (i == 4999 || field[i+1][j] == 1) {
			    min = std::min(min, i);
			    break;
			}
		    }
		}
		for (int j = q; j < p+q; j++) {
		    field[min][j] = 1;
		}
	    } else {
		for (int i = 0; i < 5000; i++) {
		    if (i == 4999 || field[i+1][q] == 1) {
			for (int j = 0; j < p; j++) {
			    field[i-j][q] = 1;
			}
			break;
		    }
		}
	    }
	    remove();
	}
	int ans = 0;
	for (int i = 0; i < 5000; i++) {
	    for (int j = 0; j < 5; j++) {
		if (field[i][j] == 1) ans++;
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
