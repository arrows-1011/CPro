#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 1010
#define INF 1e9

int dp[MAX][MAX][2];

int main()
{
    int Tc;
    cin >> Tc;
    while (Tc--) {
        int M, N;
        cin >> M >> N;
        vector<int> a(N), b(N);
        int cost = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i] >> b[i];
            cost += abs(a[i]-b[i]);
        }
        int res = INF;
        memset(dp, 1, sizeof(dp));
        dp[0][0][0] = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < 2; k++) { // k is whether r2 puts or not.
                    if (dp[i][j][k] == INF) {
                        continue;
                    }
                    if (k == 0) {
                        dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0] + abs(b[i]-a[i+1]));
                        dp[i][i+1][1] = min(dp[i][i+1][1], dp[i][j][0]);
                    } else if (k == 1 && i != j) {
                        int l = max(i, j) + 1;
                        dp[l][j][1] = min(dp[l][j][1], dp[i][j][1] + abs(b[i]-a[l]));
                        dp[i][l][1] = min(dp[i][l][1], dp[i][j][1] + abs(b[j]-a[l]));                        
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2; j++) {
                res = min(res, dp[i][N-1][j]);
                res = min(res, dp[N-1][i][j]);   
            }
        }
        cout << cost + res << endl;
    }
    return 0;
}
