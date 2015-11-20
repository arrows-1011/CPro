#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MAX 100
#define MOD 100000
int W,H;
int dp[MAX][MAX][4];
 
void make(){
    memset(dp,0,sizeof(dp));
 
    for(int i = 0 ; i < MAX ; i++){
	dp[i][0][0] = 1;
	dp[0][i][1] = 1;
    }
 
    for(int i = 1 ; i < MAX ; i++){
	for(int j = 1 ; j < MAX ; j++){
	    dp[i][j][0] += dp[i-1][j][0] + dp[i-1][j][2];
	    dp[i][j][0] %= MOD;
	    dp[i][j][1] += dp[i][j-1][1] + dp[i][j-1][3];
	    dp[i][j][1] %= MOD;
	    dp[i][j][2] += dp[i-1][j][1];
	    dp[i][j][2] %= MOD;
	    dp[i][j][3] += dp[i][j-1][0];
	    dp[i][j][3] %= MOD;
	}
    }
}
 
int main(){
    make();
    while(cin >> W >> H, (W | H)){
	int ans = 0;
	for(int i = 0 ; i < 4 ; i++){
	    ans += dp[H-1][W-1][i];
	}
	cout << ans % MOD << endl;
    }
    return 0;
}
