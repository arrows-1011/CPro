#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 10
#define MAX_M 100000
#define INF 1e9
 
int N,M,coin[MAX_N];
int dp[MAX_M+1];
 
bool c(int x){
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j <= M ; j++){
	    if(dp[j] >= 0){
		dp[j] = x;
	    }else if(j < coin[i] || dp[j-coin[i]] <= 0){
		dp[j] = -1;
	    }else{
		dp[j] = dp[j-coin[i]]-1;
	    }
	}
    }
    return (dp[M] >= 0);
}
 
int main(){
    while(cin >> N >> M,(N|M)){
	for(int i = 0 ; i < N ; i++){
	    cin >> coin[i];
	}
	sort(coin,coin+N);
	int l = 0, r = M+1;
	while(r-l > 0){
	    int m = (l + r) / 2;
	    if(c(m)){
		r = m;
	    }else{
		l = m+1;
	    }
	}
	cout << r << endl;
    }
    return 0;
}
