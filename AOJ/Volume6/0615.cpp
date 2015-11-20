#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 2010
#define prev(x) ((x-1+N)%N)
#define next(x) ((x+1)%N)
typedef long long ll;
 
ll N,A[MAX_N];
ll dp[MAX_N][MAX_N];
 
ll solve(int L,int R,int P){
    if(L == R){
	return (P == 0 ? A[L] : 0);
    }
    if(dp[L][R] >= 0) return dp[L][R];
    ll res = 0;
    if(P == 0){
	res = max(res,solve(prev(L),R,1)+A[L]);
	res = max(res,solve(L,next(R),1)+A[R]);
    }else{
	if(A[L] < A[R]){
	    res = solve(L,next(R),0);
	}else{
	    res = solve(prev(L),R,0);
	}
    }
    return dp[L][R] = res;
}
 
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> A[i];
    }
    memset(dp,-1,sizeof(dp));
    ll res = 0;
    for(int i = 0 ; i < N ; i++){
	res = max(res,solve(prev(i),next(i),1)+A[i]);
    }
    cout << res << endl;
    return 0;
}
