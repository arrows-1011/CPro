#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100
#define MAX_W 10000
#define INF 1e9

int N, W;
int v[MAX_N], w[MAX_N];

int solve()
{
    int dp[MAX_N+1][MAX_W+1];
    memset(dp, 0, sizeof(dp));
    for (int i = N-1; i >= 0; i--) {
	for (int j = 0; j <= W; j++) {
	    if (j < w[i]) {
		dp[i][j] = dp[i+1][j];
	    } else {
		dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]]+v[i]);
	    }
	}
    }
    return dp[0][W];
}

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
	cin >> v[i] >> w[i];
    }
    cout << solve() << endl;
    return 0;
}
