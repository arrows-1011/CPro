#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 10
#define MAX_S (1<<13)
 
int N,M[2*MAX_N];
int memo[2*MAX_N][MAX_S+1];
 
int solve(int p,int rem){
    if(rem == 0) return memo[p][rem] = 1;
    if(memo[p][rem] >= 0) return memo[p][rem];
    for(int i = 1 ; i <= M[p] ; i++){
	if(rem-i < 0) continue;
	if(solve((p+1)%N,rem-i) == 0){
	    return memo[p][rem] = 1;
	}
    }
    return memo[p][rem] = 0;
}
 
int main(){
    int S;
    while(cin >> N,N){
	cin >> S;
	N *= 2;
	for(int i = 0 ; i < N ; i++){
	    cin >> M[i];
	}
	memset(memo,-1,sizeof(memo));
	cout << solve(0,S) << endl;
    }
    return 0;
}
