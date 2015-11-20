#include <bits/stdc++.h>
 
using namespace std;
 
int c(char ch){
    return ch-'0';
}
 
int main(){
    string s;
    while(cin >> s, s != "0"){
	int dp[80010][11],len = s.size(),res = 0;
	memset(dp,0,sizeof(dp));
	dp[0][c(s[0])] = 1;
	for(int i = 1 ; i < len ; i++){
	    if(c(s[i]) > 0){ dp[i][c(s[i])]++; }
	    for(int j = 0 ; j < 11 ; j++){
		dp[i][(10*j+c(s[i]))%11] += dp[i-1][j];
	    }
	    res += dp[i][0];
	}
	cout << res << endl;
    }
    return 0;
}
