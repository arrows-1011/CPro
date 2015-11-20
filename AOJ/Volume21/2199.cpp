#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX_M 16
#define MAX_N 20010
#define INF 1e8
 
int N, M, C[MAX_M], x[MAX_N];
int dp[MAX_N][256];
 
int main(){
    while(cin >> N >> M , (N | M)){
	for(int i = 0 ; i < M ; i++){
	    cin >> C[i];
	}
  
	for(int i = 1 ; i <= N ; i++){
	    cin >> x[i];
	}
	int ans = INF;
	fill(dp[0], dp[MAX_N], INF);
	dp[0][128] = 0;
	for(int i = 1 ; i <= N ; i++){
	    for(int j = 0 ; j <= 255 ; j++){
		for(int k = 0 ; k < M ; k++){
		    int t = j + C[k];
		    if(t < 0) t = 0;
		    if(t > 255) t = 255;
		    dp[i][t] = min(dp[i][t], dp[i-1][j] + (t-x[i])*(t-x[i]));
		}
	    }
	}
	for(int i = 0 ; i <= 255 ; i++){
	    ans = min(ans, dp[N][i]);
	} 
	cout << ans << endl;
    }
    return 0;
}
