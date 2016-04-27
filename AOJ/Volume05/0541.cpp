#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1010
 
bool a[MAX][MAX];
int dp[MAX][MAX];
int H, W;
 
bool get_dir(int n, bool dir)
{
    return (n % 2 == 0 ? dir : !dir);
}
 
void find_last_point()
{
    int x = 0, y = 0;
    while (true) {
        if (a[y][x] == 1) {
            x++;
        } else {
            y++;
        }
        if (x >= W || y >= H) break;
    }
    cout << y+1 << " " << x+1 << endl;
}
 
int main()
{
    int N;
    while (cin >> H >> W >> N, H) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> a[i][j];
            }
        }

        memset(dp, 0, sizeof(dp));
        dp[0][0] = N-1;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (dp[i][j] == 0) continue;
                a[i][j] = get_dir(dp[i][j], a[i][j]);
                if (dp[i][j] % 2 == 1) {
                    if (a[i][j] == 0) {
                        dp[i+1][j] += dp[i][j] / 2;
                        dp[i][j+1] += dp[i][j] / 2 + 1;
                    } else {
                        dp[i+1][j] += dp[i][j] / 2 + 1;
                        dp[i][j+1] += dp[i][j] / 2;
                    }
                } else {
                    dp[i+1][j] += dp[i][j] / 2;
                    dp[i][j+1] += dp[i][j] / 2;
                }
            }
        }
        find_last_point();
    }
    return 0;
}
