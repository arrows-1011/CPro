#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)
#define Rep(i,n) for(int i = 1 ; i < n ; i++)
#define MAX 101
 
int main(){
    double dp[MAX][MAX],nae[MAX][MAX];
    int n,m;
   
    while(cin >> n >> m, n+m){
	fill(dp[0],dp[MAX-1],0);
	rep(i,n) rep(j,n) cin >> nae[i][j]; 
    
	rep(i,n) dp[0][i] = 1.0;
	Rep(i,m) rep(j,n){ dp[i][j] = -1;
	    rep(k,n)
		dp[i][j] = max(dp[i][j],dp[i-1][k]*nae[k][j]);
	}
	double ans = -1;
	rep(j,n){
	    ans = max(ans,dp[m-1][j]);
	}
	printf("%.2f\n" , ans);
    }
    return 0;
}
