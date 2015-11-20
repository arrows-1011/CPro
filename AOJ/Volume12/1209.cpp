#include <iostream>

using namespace std;

const int MAX = 301;
 
int main(){
    int n,dp[MAX];
 
    fill(dp,dp+MAX-1,0);
    dp[0] = 1;
    for(int i = 1 ; i <= 17 ; i++){
	for(int j = 0 ; j < MAX-i*i ; j++){
	    dp[i*i+j] += dp[j];
	}
    }
    while(cin >> n,n){
	cout << dp[n] << endl;
    }
    return 0;
}
