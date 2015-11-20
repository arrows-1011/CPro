#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 4001;
 
int dp[MAX][MAX];
 
int main(){
    string s1,s2;
 
    while(cin >> s1 >> s2){
	memset(dp,0,sizeof(dp));
 
	int n = s1.size() ,m = s2.size();
	int ans = 0; 
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < m ; j++){
		if(s1[i] == s2[j]){
		    dp[i+1][j+1] = dp[i][j] + 1;
		}
		ans = max(ans,dp[i+1][j+1]);
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
