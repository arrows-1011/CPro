#include <bits/stdc++.h>

using namespace std;

#define MAX_A 1010
#define MAX_B 1010
#define INF (1<<29)
typedef vector<int> Vec;

int X,Y;
int dp[MAX_A][MAX_B];

int solve(int A,int B,int p,Vec &a,Vec &b){
  if(A == X && B == Y){ return 0; }
  int &res = dp[A][B];
  if(res >= 0){
    return res;
  }
  res = (p & 1 ? INF : 0);
  if(p == 0){
    if(A < X){
      res = max(res,solve(A+1,B,1,a,b)+a[A]);
    }
    if(B < Y){
      res = max(res,solve(A,B+1,1,a,b)+b[B]);
    }
  }else{
    if(A < X){
      res = min(res,solve(A+1,B,0,a,b));
    }
    if(B < Y){
      res = min(res,solve(A,B+1,0,a,b));
    }
  }
  return res;
}

int main(){
  cin >> X >> Y;
  vector<int> a(X),b(Y);
  for(int i = 0 ; i < X ; i++){ cin >> a[i]; }
  for(int i = 0 ; i < Y ; i++){ cin >> b[i]; }
  memset(dp,-1,sizeof(dp));
  cout << solve(0,0,0,a,b) << endl;
  return 0;
}
