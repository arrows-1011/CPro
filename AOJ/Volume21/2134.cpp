#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, T;
    while (cin >> N >> T, N) {
        string s;
        cin >> s;

        vector<vector<double>> dp(T + 1, vector<double>(N));
        for (int i = 0; i < N; i++) {
            dp[0][i] = (s[i] == 'R');
        }        
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j] == 0) continue;
                for (int k = 1; k <= 6; k++) {
                    int nj = (j + k) % N;
                    dp[i + 1][nj] += dp[i][j] / 6;
                }
            }
        }
        printf("%.10f\n", *max_element(dp[T].begin(), dp[T].end()));
    }    
    return 0;
}
