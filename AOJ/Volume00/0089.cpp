#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
#define MAX 100
 
int main(){
    int n,pos = 0;
    char ch;
    vector<int> v[MAX];
 
    while(scanf("%d%c" ,&n ,&ch) != EOF){
	v[pos].push_back(n);
	if(ch == '\n'){
	    pos++;
	}
    }
  
    int dp[MAX][MAX];
    dp[0][0] = v[0][0];
    for(int i = 1 ; i < pos ; i++){
	for(int j = 0 ; j < (int)v[i].size() ; j++){
	    if(i <= pos / 2){
		if(!j){
		    dp[i][j] = v[i][j] + dp[i-1][j];
		}else if(j == (int)v[i].size()-1){
		    dp[i][j] = v[i][j] + dp[i-1][j-1];
		}else{
		    dp[i][j] = v[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
		}
	    }else{
		dp[i][j] = v[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
	    }
	}
    }
    cout << dp[pos-1][0] << endl; 
    return 0;
}
