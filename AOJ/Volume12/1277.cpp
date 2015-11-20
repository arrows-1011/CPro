#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 150
typedef pair<int,int> pii;
 
int N,T,L,B;
int arr[MAX];
 
double solve(){
    double dp[MAX][MAX]; //dp[ターン数][どのマスにいるか]
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1 ; i <= T ; i++){
	for(int j = 0 ; j < N ; j++){
	    for(int k = 0 ; k < 6 ; k++){
		if(dp[i-1][j] == 0) continue;
		int next = j+(k+1);
		if(next > N){
		    next = next - 2*(next-N);
		}
		switch(arr[next]){
		case 0:
		    dp[i][next] += dp[i-1][j]/6;
		    break;
		case 1:
		    dp[i+1][next] += dp[i-1][j]/6;
		    break;
		case 2:
		    dp[i][0] += dp[i-1][j]/6;
		    break;
		}
	    }
	}
    }
    double res = 0;
    for(int i = 1 ; i <= T ; i++){
	res += dp[i][N];
    }
    return res;
}
 
int main(){
    int in;
    while(cin >> N >> T >> L >> B, N){
	memset(arr,0,sizeof(arr));
	for(int i = 0 ; i < L ; i++){
	    cin >> in;
	    arr[in] = 1;
	}
	for(int i = 0 ; i < B ; i++){
	    cin >> in;
	    arr[in] = 2;
	}
	printf("%.8f\n",solve());
    }
    return 0;
}
