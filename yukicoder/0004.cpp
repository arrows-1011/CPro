#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_S 5000

int N,W[MAX_N],sum;

void solve(){
  bool dp[MAX_N][MAX_S+1];
  memset(dp,false,sizeof(dp));
  if(sum & 1){
    cout << "impossible" << endl;
    return;
  }
  dp[0][0] = true;
  for(int i = 0 ; i < N ; i++){
    for(int j = i ; j >= 0 ; j--){
      for(int k = MAX_S-W[i] ; k >= 0 ; k--){
        if(dp[j][k]){
          dp[j+1][k+W[i]] = true;
        }
      }
    }
  }
  bool found = false;
  for(int i = 1 ; i < N-1 ; i++){
    if(dp[i][sum/2]){
      found = true;
      break;
    }
  }
  cout << (found ? "possible" : "impossible") << endl;
}

int main(){
  cin >> N;
  for(int i = 0 ; i < N ; i++){
    cin >> W[i];
    sum += W[i];
  }
  solve();
  return 0;
}
