#include <iostream>
#include <cstring>

using namespace std;

constexpr int MOD = ((1e9) + 7);

void add(int& l, int r)
{
    l = (l + r) % MOD;
}

int main()
{
    int N;
    cin >> N;
    
    int dp[N][2][3];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {                           
                add(dp[i][0][k + 1], dp[i - 1][j][k]);
                if (j == 0) {
                    add(dp[i][1][0], dp[i - 1][j][k]);
                }                
            }
            
            if (j == 0) {
                add(dp[i][1][0], dp[i - 1][0][2]);
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            add(res, dp[N - 1][i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
