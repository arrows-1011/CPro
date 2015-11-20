#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_T 30
#define MAX_N 100
#define INF 1e9
 
int N,T,dp[MAX_N+1][MAX_T];
int arr[MAX_N],t[MAX_T],d;
 
int solve(int idx,int pos){
    if(idx == d+1) return 0;
    if(dp[idx][pos] != -1){
	return dp[idx][pos];
    }
    int res = INF;
    for(int i = 0 ; i < T ; i++){
	if(t[pos] <= arr[idx]){
	    res = min(res,solve(idx+1,(pos+1)%T));
	}
	res = min(res,solve(idx+1,1)+1);
    }
    return dp[idx][pos] = res;
}
 
int main(){
    while(cin >> T, T){
	for(int i = 0 ; i < MAX_N ; i++){
	    arr[i] = INF;
	}
	for(int i = 0 ; i < T ; i++){
	    cin >> t[i];
	}
	int D,M;
	d = 0;
	cin >> N;
	for(int i = 0 ; i < N ; i++){
	    cin >> D >> M; D--;
	    d = max(d,D);
	    arr[D] = min(arr[D],M);
	}
	memset(dp,-1,sizeof(dp));  
	cout << solve(0,0) << endl;
    }
    return 0;
}
