/*
  重さと価値がそれぞれwiとviであるようなN種類の品物がある.
  これらの品物から,重さの総和がWを超えないように選んだときの,
  価値の総和の最大値を求める.
  ただし,同じ種類の品物をいくつでも選ぶことができる.
  
  O(NW)
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int MAX_W = 10000;

int N,W;
int v[MAX_N],w[MAX_N];
int dp[MAX_N+1][MAX_W+1];

int solve(){
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j <= W ; j++){
	    if(j < w[i]){
		dp[i+1][j] = dp[i][j];
	    }else{
		dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]]+v[i]);
	    }
	}
    }
    return dp[N][W];
}

int main(){
    cin >> N >> W;
    for(int i = 0 ; i < N ; i++){
	cin >> v[i] >> w[i];
    }
    cout << solve() << endl;
    return 0;
}
