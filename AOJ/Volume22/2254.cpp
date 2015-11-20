#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 18;
const int INF = 1<<29;
 
int t[MAX][MAX], n;
int dp[1<<16];
 
int solve(){
    for(int i = 0 ; i < (1<<n) ; i++){
	dp[i] = INF;
    }
 
    dp[0] = 0;
    for(int i = 0 ; i < (1<<n) ; i++){
	for(int j = 0 ; j < n ; j++){
	    if(!(i & (1<<j))){
		dp[i + (1<<j)] = min(dp[i + (1<<j)], t[j][0] + dp[i]);
		for(int k = 0 ; k < n ; k++){
		    if(i & (1<<k)){
			dp[i + (1<<j)] = min(dp[i + (1<<j)],dp[i]+t[j][k+1]);
		    }
		}
	    }
	}
    }
    return dp[(1<<n)-1];
}
 
int main(){
    while(cin >> n ,n){
	memset(t,0,sizeof(t));
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j <= n ; j++){
		cin >> t[i][j];
	    }
	}    
	cout << solve() << endl;
    }
    return 0;
}
