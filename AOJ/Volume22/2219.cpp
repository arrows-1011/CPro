#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 350
 
int N, M;
int cost[MAX];
int rank[MAX][3];
 
void solve(){
    int dp[MAX][MAX][3];
    memset(dp, 0, sizeof(dp));
 
    int ans = 0;
    for(int k = 0 ; k < 3 ; k++){
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j <= M ; j++){
		if(j-cost[i] < 0){
		    dp[i+1][j][k] = dp[i][j][k];
		}else{
		    dp[i+1][j][k] = max(dp[i][j][k],dp[i+1][j-cost[i]][k] + rank[i][k]);
		}
	    }
	}
	ans = max(ans, dp[N][M][k]);
    }
    cout << ans << endl;
}
 
int main(){
    string str;
    while(cin >> N >> M){
	for(int i = 0 ; i < N ; i++){
	    cin.ignore(); 
	    getline(cin,str);
	    cin >> cost[i] >> rank[i][0] >> rank[i][1] >> rank[i][2];
	}
	solve();
    }
    return 0;
}
