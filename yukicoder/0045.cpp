#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        dp[i][i] = a[i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i - 1][j] == -1) continue;
            if (j < i - 1) {
                dp[i][i] = max(dp[i][i], dp[i - 1][j] + a[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    int res = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
