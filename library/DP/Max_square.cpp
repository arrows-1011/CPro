/*
  matは、'.'と'*'で構成されており、
  '.'でできる最大の正方形の1辺の長さを求める。
  resをres*resにすると面積になる。
*/

#include <iostream>

using namespace std;

#define MAX 1010

int N;
char mat[MAX][MAX];

int maximum_square()
{
    int dp[MAX][MAX], res = 0;
    for (int i = 0; i < N; i++) {
	dp[0][i] = !(mat[0][i] == '*');
	dp[i][0] = !(mat[i][0] == '*');
	if (mat[0][i] == '.') res = 1;
	if (mat[i][0] == '.') res = 1;
    }
    for (int i = 1; i < N; i++) {
	for (int j = 1; j < N; j++) {
	    if (mat[i][j] == '*') {
		dp[i][j] = 0;
	    } else {
		dp[i][j] = min(dp[i-1][j-1],
			       min(dp[i-1][j], dp[i][j-1])) + 1;
		res = max(dp[i][j], res);
	    }
	}
    }
    return res;
}

int main()
{
    while (cin >> N, N) {
	for (int i = 0; i < N; i++) { 
	    for (int j = 0; j < N; j++) {
		cin >> mat[i][j];
	    }
	}
	cout << maximum_square() << endl;
    }
    return 0;
}
