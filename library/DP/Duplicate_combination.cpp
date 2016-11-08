/*
  n種類の品物があり、i番目の品物はai個ある。異なる種類の品物同士は区別できるが、同じ種類の品物同士
  は区別できない。これらの品物の中からm個選ぶ組み合わせの総数を求め、Mで割った余りを答えよ。

  O(nm)
*/

#include <iostream>

using namespace std;

constexpr int MAX_M = 1000;
constexpr int MAX_N = 1000;
constexpr int M = 10000;

//入力
int n, m;
int a[MAX_N];

int dp[MAX_N + 1][MAX_M + 1]; //DPテーブル

void solve()
{
    //1つも選ばない方法は常に1通り
    for (int i = 0; i <= n; i++) {
	dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
	for (int j = 1; j <= m; j++) {
	    if (j - 1 - a[i] >= 0) {
		//引き算が含まれる場合には負の数にならないよう注意する
		dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
	    } else {
		dp[i + 1][j] = (dp[i + 1][j - 1] + dp[i][j]) % M;
	    }
	}
    }
    cout << dp[n][m] << endl;
}
