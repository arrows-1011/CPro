#include <bits/stdc++.h>

using namespace std;
 
#define MAX 1000
 
int solve(int size, char g[MAX][MAX])
{
    int dp[MAX][MAX];
     
    for (int i = 0; i < size; i++) {
        dp[0][i] = (g[0][i] == '*') ? 0 : 1;
        dp[i][0] = (g[i][0] == '*') ? 0 : 1;
    }
 
    int mw = 0;
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (g[i][j] =='*') {
                dp[i][j] = 0;
            } else{
                dp[i][j] = min(dp[i-1][j-1] ,min(dp[i-1][j], dp[i][j-1])) + 1;
                mw = max(mw, dp[i][j]);
            }
        }
    }
    return mw;
}
 
int main()
{
    int n;
    char g[MAX][MAX];
    while (cin >> n, n) {
	for (int i = 0; i < n; i++) {
	    for (int j = 0; j < n; j++) {
		cin >> g[i][j];
	    }
	}
	cout << solve(n, g) << endl;
    }
    return 0;
}
