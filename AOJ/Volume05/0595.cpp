#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 10007
 
int N,dp[1050][1<<3];
char sch[1050];
 
int getNum(char c){
    if(c == 'J'){
	return 0;
    }else if(c == 'O'){
	return 1;
    }
    return 2;
}
 
int main(){
    cin >> N >> sch;
    memset(dp,0,sizeof(dp));
   
    for(int i = 0 ; i < (1<<3) ; i++){
	if((1<<getNum('J') & i) && (1<<getNum(sch[0]) & i)){
	    dp[0][i] = 1;
	}
    }
    for(int i = 1 ; i < N ; i++){
	for(int j = 0 ; j < (1<<3) ; j++){
	    for(int k = 0 ; k < (1<<3) ; k++){
		if(j & k){
		    if(!(k & (1<<getNum(sch[i])))) continue;
		    dp[i][k] = dp[i][k] + dp[i-1][j];
		    dp[i][k] %= MOD;
		}
	    }
	}
    }
    int ans = 0;
    for(int i = 0 ; i < (1<<3) ; i++){
	ans += dp[N-1][i];
	ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
