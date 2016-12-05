#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX = 55;
constexpr int MAX_S = 850;
constexpr int INF = (1 << 20);

void update(int& l, int r)
{
    if (l > r) l = r;
}

int dp[MAX][MAX_S][MAX_S];

int main()
{
    int N, sum = 0;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; i++) {
        cin >> T[i];
        sum += T[i];
    }

    sort(T.begin(), T.end());    

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < MAX_S; j++) {
            for (int k = 0; k < MAX_S; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    
    dp[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < MAX_S - T[i]; j++) {
            for (int k = 0; k < MAX_S - T[i]; k++) {
                update(dp[i + 1][j + T[i]][k], dp[i][j][k] + 1);
                update(dp[i + 1][j][k + T[i]], dp[i][j][k] + 1);
                update(dp[i + 1][j][k], dp[i][j][k] + 1);
            }
        }
    }

    int res = INF;
    for (int i = 0; i < MAX_S; i++) {
        for (int j = 0; j < MAX_S; j++) {
            if (dp[N][i][j] != INF) {
                res = min(res, max(i, max(j, sum - i - j)));
            }
        }
    }
    cout << res << endl;
    return 0;
}
