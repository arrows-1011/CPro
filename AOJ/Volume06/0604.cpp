#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_M 2048
#define MAX_N 2048

int dp[MAX_M][MAX_N][2];

int main()
{
    int M, N;
    char ch;
    cin >> M >> N;
    vector<int> S(M), T(N);
    for (int i = 0; i < M; i++) {
        cin >> ch;
        S[i] = (ch == 'I' ? 1 : 0);
    }
    for (int i = 0; i < N; i++) {
        cin >> ch;
        T[i] = (ch == 'I' ? 1 : 0);
    }
    
    memset(dp, -1, sizeof(dp));
    
    for (int i = 0; i < M; i++) {
        if (S[i] == 1) {
            for (int j = 0; j < N; j++) {
                dp[i+1][j][1] = 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (T[i] == 1) {
            for (int j = 0; j < M; j++) {
                dp[j][i+1][1] = 1;
            }
        }
    }
    
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i][j][k] == -1) continue;
                if (S[i] == 1-k) {                    
                    dp[i+1][j][1-k] = max(dp[i+1][j][1-k],
                                          dp[i][j][k] + 1);
                }
                if (T[j] == 1-k) {
                    dp[i][j+1][1-k] = max(dp[i][j+1][1-k],
                                          dp[i][j][k] + 1);
                }                
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            res = max(res, dp[i][j][1]);   
        }
    }
    cout << res << endl;
    return 0;
}
