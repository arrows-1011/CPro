#include <bits/stdc++.h>

using namespace std;

#define MAX 11
 
int main()
{
    int n, mat[MAX][MAX];
     
    while (cin >> n, n) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                mat[i][j] = 0;
	    }
	}
         
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
	    }
	}
         
        int sum = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                sum += mat[i][j];
                if (j == n) {
                    mat[i][j] = sum;
                    sum = 0;
                }
                 
            }
        }
         
        for (int j = 0; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                sum += mat[i][j];
                if (i == n) {
                    mat[i][j] = sum;
                    sum = 0;
                }
            }
        }
         
        int e = 0;
        for (int i = 0; i < n; i++) {
            e += mat[n][i];
            if (i == n-1) mat[n][n] = e;
        }
         
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
		printf("%5d", mat[i][j]);
            }
            cout << endl;
        }
    }
    return 0;
}
