#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> sum(M, vector<int>(N + 1));
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        sum[--x][i + 1] = 1;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    
    constexpr int INF = 114514;
    vector<int> dp(1 << M, INF);    
    dp[0] = 0;
    
    for (int i = 0; i < (1 << M); i++) {
        int s = 0;
        for (int j = 0; j < M; j++) {
            if (i >> j & 1) {
                s += sum[j][N];
            }
        }
        for (int j = 0; j < M; j++) {
            if (i >> j & 1) continue;
            int ni = i | (1 << j);
            int cost = sum[j][N] - sum[j][s + sum[j][N]] + sum[j][s];
            dp[ni] = min(dp[ni], dp[i] + cost);
        }
    }    
    cout << dp[(1 << M) - 1] << endl;    
    return 0;
}
