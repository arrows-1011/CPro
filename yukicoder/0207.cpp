#include <bits/stdc++.h>

using namespace std;

bool check(int x){
  if(x % 3 == 0){
    return true;
  }
  while(x > 0){
    if(x % 10 == 3){
      return true;
    }
    x /= 10;
  }
  return false;
}

int main(){
  int A,B;
  cin >> A >> B;
  for(int i = A ; i <= B ; i++){
    if(check(i)){
      cout << i << endl;
    }
  }
  return 0;
}
