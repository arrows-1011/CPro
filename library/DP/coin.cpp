#include <bits/stdc++.h>

using namespace std;

#define MAX 60010
#define MAX_C 20
#define INF 1e9

int N,M;
int c[MAX_C];

int solve(){
    int dp[MAX];
    fill(dp,dp+MAX,INF);
    dp[0] = 0;
    for(int i = 0 ; i < M ; i++){
	for(int j = c[i] ; j <= N ; j++){
	    dp[j] = min(dp[j],dp[j-c[i]] + 1);
	}
    }
    return dp[N];
}

int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0 ; i < M ; i++){
	scanf("%d",&c[i]);
    }
    printf("%d\n",solve());
    return 0;
}
