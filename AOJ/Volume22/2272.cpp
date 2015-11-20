#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 51
 
int main(){
    int n,m,dp[MAX][MAX];
    string str[MAX];
 
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
	cin >> str[i];
    }
    fill(dp[0],dp[MAX-1],0); 
 
    dp[0][0] = str[0][0]-'0';
    for(int i = 1 ; i < n ; i++){
	dp[i][0] = dp[i-1][0] + (str[i][0]-'0');
    }
 
    for(int j = 1 ; j < m ; j++){
	dp[0][j] = dp[0][j-1] + (str[0][j]-'0');
    }
 
    for(int i = 1 ; i < n ; i++){
	for(int j = 1 ; j < m ; j++){
	    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+(str[i][j]-'0');
	}
    }
    cout << dp[n-1][m-1] << endl;
    return 0;
}
