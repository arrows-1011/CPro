/*
  n個の互いに区別できない品物を、m個以下に分割する方法の総数を求め、
  Mで割った余りを求める。

  O(nm)
*/

#include <iostream>

using namespace std;

constexpr int MOD = 10000;
constexpr int MAX_M = 1000;
constexpr int MAX_N = 1000;

int n, m;

int dp[MAX_M + 1][MAX_N + 1]; //DPテーブル

void solve()
{
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
	for (int j = 0; j <= n; j++) {
	    if (j - i >= 0) {
		dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
	    } else {
		dp[i][j] = dp[i - 1][j];
	    }
	}
    }
    printf("%d\n", dp[m][n]);
}
