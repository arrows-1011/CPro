#include <bits/stdc++.h>

using namespace std;

#define MAX 150

int main()
{
    int N, M;
    while (cin >> N >> M, N) {
        double g[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> g[i][j];
            }
        }
        
        double dp[MAX][MAX];
        for (int i = 0; i < MAX; i++) {            
            for (int j = 0; j < MAX; j++) {
                dp[i][j] = (j == 0 ? 1 : 0);
            }
        }

        for (int i = 0; i < M-1; i++) {
            for (int j = 0; j < N; j++) {                
                for (int k = 0; k < N; k++) {
                    dp[k][i+1] = max(dp[k][i+1],
                                       dp[j][i] * g[j][k]);
                }
            }
        }
        
        double res = 0;
        for (int i = 0; i < N; i++) {
            res = max(res, dp[i][M-1]);
        }
        printf("%.2f\n", res);
    }
    return 0;
}
