#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1<<29;
 
int main(){
    int n;
    int dp[51];
    int c[6] = {380,550,850,1520,1870,2244};
    int d[6] = {2,3,5,10,12,15};
 
    fill(dp,dp+51,INF);
    dp[0] = 0;
    for(int i = 0 ; i < 51 ; i++){
	for(int j = 0 ; j < 6 ; j++){
	    if(d[j] <= i){
		dp[i] = min(dp[i],dp[i-d[j]]+c[j]);
	    }
	}
    }  
 
    while(cin >> n , n){
	n /= 100;
	cout << dp[n] << endl;
    }
    return 0;
}
