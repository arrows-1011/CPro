#include <bits/stdc++.h>

using namespace std;

map<int,int> prime_factorize(int n){
  map<int,int> res;
  for(int i = 2 ; i*i <= n ; i++){
    while(n % i == 0){
      res[i]++;
      n /= i;
    }
  }
  if(n != 1){ res[n]++; }
  return res;
}

int main(){
  int N;
  cin >> N;
  map<int,int> pf = prime_factorize(N);
  int x = 0;
  for(auto i : pf){
    x ^= i.second;
  }
  cout << (x ? "Alice" : "Bob") << endl;
  return 0;
}
