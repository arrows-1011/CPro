#include <bits/stdc++.h>

using namespace std;

#define MAX_N 110
#define MAX_P 10010

int main(){
  int N,p[MAX_N];
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    cin >> p[i];
  }
  bool dp[MAX_P];
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  for(int i = 0 ; i < N ; i++){
    for(int j = MAX_P-1 ; j >= 0 ; j--){
      if(j + p[i] >= MAX_P){ continue; }
      if(dp[j]){ dp[j+p[i]] = 1; }
    }
  }
  cout << count(dp,dp+MAX_P,1) << endl;
  return 0;
}
