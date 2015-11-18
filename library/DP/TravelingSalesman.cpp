#include <bits/stdc++.h>

using namespace std;

#define MAX_V 15
#define INF 1e9

int V,E;
int d[MAX_V][MAX_V];
int dp[1<<MAX_V][MAX_V];

int rec(int S,int v){
  if(dp[S][v] >= 0){
    return dp[S][v];
  }
  if(S == (1<<V)-1 && v == 0){
    return dp[S][v] = 0;
  }
  int res = INF;
  for(int u = 0 ; u < V ; u++){
    if(!(S >> u & 1)){
      res = min(res,rec(S|1<<u,u) + d[v][u]);
    }
  }
  return dp[S][v] = res;
}

void init(){
  memset(dp,-1,sizeof(dp));
  fill(d[0],d[0]+MAX_V*MAX_V,INF);
}

int main(){
  init();
  cin >> V >> E;
  for(int i = 0 ; i < E ; i++){
    int a,b,c;
    cin >> a >> b >> c;
    d[a][b] = c;
  }
  int res = rec(0,0);
  cout << (res == INF ? -1 : res) << endl;
  return 0;
}
