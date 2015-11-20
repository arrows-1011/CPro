#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
#define MAX 200
#define MAX_T 60
typedef pair<int,int> P;
 
int T[MAX],D,dp[MAX][MAX];
vector<P> vec[MAX_T+1];
 
int solve(int d,P prev){
    if(d == D) return 0;
    if(dp[d][prev.second] >= 0) return dp[d][prev.second];
    int res = 0;
    for(int i = 0 ; i < (int)vec[T[d]].size() ; i++){
	int diff = abs(vec[T[d]][i].first-prev.first);
	res = max(res,solve(d+1,vec[T[d]][i])+diff);
    }
    return dp[d][prev.second] = res; 
}
 
int main(){
    int N,A,B,C;
    memset(dp,-1,sizeof(dp));
 
    scanf("%d%d",&D,&N);
    for(int i = 0 ; i < D ; i++){
	scanf("%d",&T[i]);
    }
    for(int i = 0 ; i < N ; i++){
	scanf("%d%d%d",&A,&B,&C);
	for(int j = A ; j <= B ; j++){
	    vec[j].push_back(P(C,i));
	}
    }
    int ans = 0;
    for(int i = 0 ; i < (int)vec[T[0]].size() ; i++){
	ans = max(ans,solve(1,vec[T[0]][i]));
    }
    printf("%d\n",ans);
    return 0;
}
