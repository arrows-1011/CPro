#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
typedef long long ll;
 
int N,M;
ll dp[MAX][1<<16],L[MAX];
int bit[MAX];

ll solve(int n,int S){
    if(n == N) return 0LL;
    if(dp[n][S] != -1){
	return dp[n][S];
    }
    ll res = 0LL;
    res = max(res,solve(n+1,S));
    bool ok = true;
    for(int i = 0 ; i < 16 ; i++){
	if((S >> i) & (bit[n] >> i)){
	    ok = false;
	    break;
	}
    }
    if(ok){
	res = max(res,solve(n+1,S|bit[n])+L[n]);
    }
    return dp[n][S] = res;
}
 
int main(){
    int S,E;
    while(cin >> N, N){
	memset(dp,-1,sizeof(dp));
	for(int i = 0 ; i < N ; i++){
	    cin >> M >> L[i]; bit[i] = 0;
	    for(int j = 0 ; j < M ; j++){
		cin >> S >> E;
		S -= 6; E -= 6;
		for(int k = S ; k < E ; k++){
		    bit[i] |= (1<<k);
		}
	    }
	}
	cout << solve(0,0) << endl;
    }
    return 0;
}
