#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
#define MAX 30
 
int N,C,dp[MAX][1<<16];
int a[MAX],b[MAX+1];
 
int solve(int cur,int p){
    if(cur == N) return 0;
    if(dp[cur][p] >= 0) return dp[cur][p];
    int res = 0;
    for(int i = 0 ; i < C ; i++){
	int S = (a[cur] | p) & b[i];
	int next = ((a[cur] | p) ^ b[i]) & (a[cur] | p);
	res = max(res,solve(cur+1,next) + __builtin_popcount(S));
    }
    return dp[cur][p] = res;
}
 
int main(){
    int in,S;
    while(cin >> N >> C,(N | C)){
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i < N ; i++){
	    S = 0;
	    for(int j = 0 ; j < 16 ; j++){
		cin >> in;
		if(in){
		    S |= 1<<j;
		}
	    }
	    a[i] = S;
	}
	for(int i = 0 ; i < C ; i++){
	    S = 0;
	    for(int j = 0 ; j < 16 ; j++){
		cin >> in;
		if(in){
		    S |= 1<<j;
		}
	    }
	    b[i] = S;
	}
	cout << solve(0,0) << endl;
    }
    return 0;
}
