#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
#define MAX_N 8
#define MAX_M 30
#define INF (1<<29)
 
int N,M,a,b,t[MAX_N];
int d[MAX_M][MAX_M];
double dp[1<<MAX_N][MAX_M];
 
void solve(){
    for(int i = 0 ; i < 1<<N ; i++){
	fill(dp[i],dp[i]+M,INF);
    }
    dp[(1<<N)-1][a-1] = 0;
    double res = INF;
    for(int S = (1<<N)-1 ; S >= 0 ; S--){
	res = min(res,dp[S][b-1]);
	for(int v = 0 ; v < M ; v++){
	    for(int i = 0 ; i < N ; i++){
		if(S >> i & 1){
		    for(int u = 0 ; u < M ; u++){
			if(d[v][u] >= 0){
			    dp[S & ~(1<<i)][u] = min(dp[S & ~(1<<i)][u],
						     dp[S][v]+(double)d[v][u]/t[i]);
			}
		    }
		}
	    }
	}
    }
    if(res == INF){
	puts("Impossible");
    }else{
	printf("%.3f\n",res);
    }
}
 
int main(){
    int p;
    while(true){
	scanf("%d%d%d%d%d",&N,&M,&p,&a,&b);
	if(!N && !M && !p && !a && !b) break;
	memset(d,-1,sizeof(d));
	for(int i = 0 ; i < N ; i++){
	    scanf("%d",&t[i]);
	}
	for(int i = 0 ; i < p ; i++){
	    int x,y,z;
	    scanf("%d%d%d",&x,&y,&z);
	    d[x-1][y-1] = d[y-1][x-1] = z;
	}
	solve();
    }
    return 0;
}
