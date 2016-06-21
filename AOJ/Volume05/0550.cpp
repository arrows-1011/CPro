#include <bits/stdc++.h>

using namespace std;

#define INF (1e9)

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N-1; i++) {
        cin >> a[i];
    }

    int dp[2][5010][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5010; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        int curr = (i & 1), next = (~i & 1);
        for (int j = 0; j <= N/2; j++) {
            dp[next][j+1][0] = min(dp[curr][j][0], dp[curr][j][1] + a[i]);
            dp[next][j][1] = min(dp[curr][j][1], dp[curr][j][0] + a[i]);
        }
        dp[curr][0][0] = INF;
    }
    cout << dp[N%2][N/2][0] << endl;
    return 0;
}
