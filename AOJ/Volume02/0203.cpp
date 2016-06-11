#include <bits/stdc++.h>

using namespace std;

#define MAX 25

int main()
{
    int H, W;
    while (cin >> W >> H, W) {
        vector<vector<int>> a(H, vector<int>(W));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> a[i][j];
            }
        }
        int dp[MAX][MAX] = {{}};
        for (int i = 0; i < W; i++) {
            dp[0][i] = (a[0][i] == 0);
        }

        for (int i = 0; i < H - 1; i++) {
            for (int j = 0; j < W; j++) {
                if (dp[i][j] <= 0 || a[i][j] == 1) continue;
                if (a[i][j] == 2) {
                    int ni = min(i + 2, H - 1);
                    if (i + 2 < H && a[i+2][j] == 1) continue;
                    dp[ni][j] += dp[i][j];
                } else {
                    for (int k = -1; k <= 1; k++) {
                        int ni = i + 1;
                        int nj = j + k;
                        if (nj < 0 || nj >= W) continue;
                        if (a[ni][nj] == 1) continue;
                        if (a[ni][nj] == 2 && j != nj) continue;
                        dp[ni][nj] += dp[i][j];
                    }
                }
            }
        }
        int res = 0;
        for (int i = 0; i < W; i++) {
            res += dp[H-1][i];
        }
        cout << res << endl;
    }
    return 0;
}
