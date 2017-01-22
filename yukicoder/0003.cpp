#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10001
#define INF (1<<29)

int main(){
  int N;
  int d[MAX_N];
  cin >> N;
  for(int i = 1 ; i <= N ; i++){
    d[i] = INF;
  }
  queue<int> Q; Q.push(1);
  d[1] = 1;
  bool found = false;
  while(!Q.empty()){
    int v = Q.front(); Q.pop();
    if(v == N){
      cout << d[v] << endl;
      found = true;
      break;
    }
    int bit = __builtin_popcount(v);
    int to = v - bit, to2 = v + bit;
    if(1 <= to && to <= N){
      if(d[v]+1 < d[to]){
        d[to] = d[v]+1;
        Q.push(to);
      }
    }
    if(1 <= to2 && to2 <= N){
      if(d[v]+1 < d[to2]){
        d[to2] = d[v]+1;
        Q.push(to2);
      }
    }
  }
  if(!found){
    cout << -1 << endl;
  }
  return 0;
}
