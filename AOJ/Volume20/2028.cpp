#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100
 
int N,arr[MAX_N];
int dp[MAX_N][MAX_N];
 
int rec(int L,int R){
    if(L == R) return dp[L][R] = 0;
    if(dp[L][R] >= 0) return dp[L][R];
    int res = 0;
    int i = L;
    while(i != R){
	int j = i%N,k = (i+1)%N;
	res = max(res,rec(L,j)+rec(k,R)+abs(arr[L]-arr[k]));
	i++; i %= N;
    }
    return dp[L][R] = res;
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	cin >> N;
	for(int i = 0 ; i < N ; i++){
	    cin >> arr[i];
	}
	memset(dp,-1,sizeof(dp));
	int res = 0;
	for(int i = 0 ; i < N ; i++){
	    int j = (i+N-1)%N;
	    res = max(res,rec(i,j));
	}
	cout << res << endl;
    }
    return 0;
}
