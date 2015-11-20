#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1010
#define MAX_M 1010
#define INF 1e9
 
int main(){
    int N,M,D[MAX_N],C[MAX_M];
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
	cin >> D[i];
    }
    for(int i = 0 ; i < M ; i++){
	cin >> C[i];
    }
    int dp[MAX_N][MAX_M];
    fill(dp[0],dp[0]+MAX_N*MAX_M,INF);
    dp[0][0] = 0;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < M ; j++){
	    dp[i][j+1] = min(dp[i][j+1],dp[i][j]);
	    dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+D[i]*C[j]);
	}
    }
    cout << *min_element(dp[N],dp[N]+M+1) << endl;
    return 0;
}
