/*
  O(n^2)
*/

#include <bits/stdc++.h>

using namespace std;

#define MAX_N 1000

//入力
int n;
int a[MAX_N];

int dp[MAX_N]; //DPテーブル

void solve(){
    int res = 0;
    for(int i = 0 ; i < n ; i++){
	dp[i] = 1;
	for(int j = 0 ; j < i ; j++){
	    if(a[j] < a[i]){
		dp[i] = max(dp[i],dp[j]+1);
	    }
	}
	res = max(res,dp[i]);
    }
    printf("%d\n",res);
}
