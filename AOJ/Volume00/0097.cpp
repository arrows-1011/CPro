#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_N = 10;
const int MAX_S = 1001;
 
ll dp[MAX_N][MAX_S];
 
void init()
{
    for (int i = 0; i <= MAX_N*MAX_N; i++) {
	dp[1][i] = 1;
    }
    for (int i = 2; i < MAX_N; i++) {
	for (int j = 1; j < MAX_S; j++) {
	    if(j >= i) dp[i][j] += dp[i][j-i];
	    if(j >= (i-1)) dp[i][j] += dp[i-1][j-(i-1)];
	    if(j >= 101) dp[i][j] -= dp[i-1][j-101];
	}
    }
}
 
int main()
{
    int n, s;
    init();
    while (cin >> n >> s, (n + s)) {
	cout << dp[n][s] << endl;
    }
    return 0;
}
