#include <cstdio>
#include <algorithm>
 
using namespace std;
 
const int INF = 1e9;
const int MAX = 100;
 
int main(){
    int n,r[MAX],c[MAX];
    int dp[MAX][MAX];
 
    scanf("%d" ,&n);
    for(int i = 0 ; i < n ; i++){
	scanf("%d %d" ,&r[i] , &c[i]);
    }
 
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < n ; j++){
	    dp[i][j] = INF;
	}
    }
 
    for(int i = 0 ; i < n ; i++){
	dp[i][i] = 0;
    }
  
    for(int i = 1 ; i < n ; i++){
	for(int j = 0 ; j < n-i ; j++){
	    for(int k = j ; k < i + j ; k++){
		int M = r[j] * c[k] * r[k+1] * c[i+j];
		dp[j][i+j] = min(dp[j][i+j],dp[j][k] + dp[k+1][i+j] + M);
	    }
	}
    }
    printf("%d\n" ,dp[0][n-1]);
    return 0;
}
