#include <bits/stdc++.h>
 
using namespace std;
 
int M,W,memo[13][1<<13];
vector<int> A,B;
 
int getEn(int bm,int bw){
    int x = abs(bm-bw);
    return x*pow(x-30,2);
}
 
int solve(int idx,int S){
    if(idx == M){ return memo[idx][S] = 0; }
    if(memo[idx][S] >= 0){ return memo[idx][S]; }
    int res = -1;
    for(int i = 0 ; i < W ; i++){
	if(S >> i & 1){ continue; }
	res = max(res,solve(idx+1,S|(1<<i))+getEn(A[idx],B[i]));
    }
    return memo[idx][S] = res;
}
 
int main(){
    while(cin >> M >> W, M){
	A.resize(M); B.resize(W);
	for(int i = 0 ; i < M ; i++){ cin >> A[i]; }
	for(int i = 0 ; i < W ; i++){ cin >> B[i]; }
	if(M > W){ swap(M,W); swap(A,B); }
	memset(memo,-1,sizeof(memo));
	cout << solve(0,0) << endl;
    }
    return 0;
}
