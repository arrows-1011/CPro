#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  int n;
  cin >> n;
  
  ll dp[n+1];
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  for(int i = 0 ; i < n ; i++){
    for(int j = 1 ; j <= 2 ; j++){
      if(i+j > n){ continue; }
      dp[i+j] += dp[i];
    }
  }
  cout << dp[n] << endl;
  return 0;
}
