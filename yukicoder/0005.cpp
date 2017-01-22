#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10000

int main(){
  int L,N,W[MAX_N];
  cin >> L >> N;
  for(int i = 0 ; i < N ; i++){
    cin >> W[i];
  }
  sort(W,W+N);
  int sum = 0;
  bool ok = false;
  for(int i = 0 ; i < N ; i++){
    sum += W[i];
    if(sum > L){
      ok = true;
      cout << i << endl;
      break;
    }
  }
  if(!ok){
    cout << N << endl;
  }
  return 0;
}
