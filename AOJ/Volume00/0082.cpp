#include <bits/stdc++.h>

using namespace std;
 
int main()
{
    int a[8][8] = {
	{1, 2, 1, 2, 1, 4, 1, 4},
	{1, 2, 1, 4, 1, 4, 1, 2},
	{1, 4, 1, 2, 1, 2, 1, 4},
	{1, 4, 1, 4, 1, 2, 1, 2},
	{2, 1, 2, 1, 4, 1, 4, 1},
	{2, 1, 4, 1, 4, 1, 2, 1},
	{4, 1, 2, 1, 2, 1, 4, 1},
	{4, 1, 4, 1, 2, 1, 2, 1}
    }; 
 
    int b[8];
 
    while (~scanf("%d" ,&b[0])) {
	int ans[8], min_ = (1<<29);
	for(int i = 1 ; i < 8 ; i++){
	    scanf("%d" ,b + i);
	}
     
	for (int i = 0; i < 8; i++) {           
	    int npas = 0;
	    for (int j = 0; j < 8; j++) {
		int d = b[j] - a[i][j];
		if (d > 0) {
		    npas += d;
		}
	    }
	    if (min_ > npas) {
		min_ = npas;
		for (int j = 0; j < 8; j++) {
		    ans[j] = a[i][j]; 
		}
	    }
	}
 
	for (int i = 0; i < 8; i++) {
	    if (i != 7) {
		printf("%d ", ans[i]);
	    } else {
		printf("%d\n", ans[i]);
	    }
	}
    }
    return 0;
}
