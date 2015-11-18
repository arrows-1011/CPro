/*
  O(V^3)
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX_V 100
#define INF 1e9

int d[MAX_V][MAX_V]; //d[u][v]は辺e=(u,v)のコスト(存在しない場合INF,d[i][i]=0)
int V;               //頂点数

void warshall_floyd(){
  for(int k = 0 ; k < V ; k++){
    for(int i = 0 ; i < V ; i++){
      for(int j = 0 ; j < V ; j++){
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
}

/*
  負の閉路判定 ver
 */

bool checkNegativeCycle(){
  for(int i = 0 ; i < V ; i++){
    if(d[i][i] < 0){
      return true;
    }
  }
  return false;
}

void warshall_floyd2(){
  for(int k = 0 ; k < V ; k++){
    for(int i = 0 ; i < V ; i++){
      for(int j = 0 ; j < V ; j++){
        if(d[i][k] != INF && d[k][j] != INF){
          d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
        }
      }
    }
  }
  if(checkNegativeCycle()){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    for(int i = 0 ; i < V ; i++){
      for(int j = 0 ; j < V ; j++){
        if(d[i][j] == INF){
          //頂点iから頂点jには到達不可能
        }else{
          //頂点iから頂点jの最短経路
        }
      }
    }
  }
}
