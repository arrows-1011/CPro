#include <bits/stdc++.h>

using namespace std;

double R[1<<10];

double getPro(int a,int b){
  return 1.0 / (1.0 + pow(10,(R[b]-R[a])/400));
}

int main(){
  int K;
  cin >> K;
  for(int i = 0 ; i < (1<<K) ; i++){
    cin >> R[i];
  }
  double dp[11][1<<11];
  for(int i = 0 ; i < (1<<K) ; i++){
    dp[0][i] = 1;
  }
  for(int i = 0 ; i < K ; i++){
    for(int j = 0 ; j < (1<<K) ; j++){
      for(int k = 0 ; k < (1<<K) ; k++){
        if(j == k){ continue; }
        if(j/(1<<(i+1)) != k/(1<<(i+1))){ continue; }
        if(j/(1<<i) == k/(1<<i)){ continue; }
        dp[i+1][j] += dp[i][j]*dp[i][k]*getPro(j,k);
      }
    }

  }
  for(int i = 0 ; i < (1<<K) ; i++){
    printf("%.10f\n",dp[K][i]);
  }
  return 0;
}
