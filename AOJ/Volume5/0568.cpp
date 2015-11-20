#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MOD 10000
#define MAX 100
 
int dp[MAX+1][4][4],p[MAX],N;
 
int solve(int pos,int a,int b){
    if(pos == N) return 1; 
    if(dp[pos][a][b] != -1) return dp[pos][a][b];
 
    if(p[pos] > 0){
	if(a == b && b == p[pos]){
	    return 0;
	}else{
	    return solve(pos+1,b,p[pos]) % MOD;
	}
    }else{
	int res = 0;
	for(int i = 0 ; i < 3 ; i++){
	    if(a == b && b == i+1) continue;
	    res += solve(pos+1,b,i+1) % MOD;
	}
	return dp[pos][a][b] = res % MOD;
    }
}
 
int main(){
    int K,A,B;
 
    memset(p,-1,sizeof(p));
    memset(dp,-1,sizeof(dp));
 
    cin >> N >> K;
    for(int i = 0 ; i < K ; i++){
	cin >> A >> B;
	p[A-1] = B;
    }
    cout << solve(0,0,0) << endl;
    return 0;
}
