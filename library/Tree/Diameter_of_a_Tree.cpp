#include <bits/stdc++.h>

using namespace std;

#define MAX_V 100010
#define INF (1<<29)

struct Edge{
  int to,cost;
  Edge(int to,int cost) : to(to),cost(cost) {}
};

int V,maxi,start;
int dist[MAX_V];
bool visited[MAX_V];
vector<Edge> G[MAX_V];

void getStart(int v,int d){
  if(dist[v] < INF){ return; }
  dist[v] = d;
  if(maxi < d){ maxi = d; start = v; }
  for(int i = 0 ; i < (int)G[v].size() ; i++){
    Edge e = G[v][i];
    getStart(e.to,d+e.cost);
  }
}

int getTreeDiameter(int v){
  int res = 0;
  for(int i = 0 ; i < (int)G[v].size() ; i++){
    Edge e = G[v][i];
    if(!visited[e.to]){
      visited[e.to] = true;
      res = max(res,e.cost+getTreeDiameter(e.to));
    }
  }
  return res;
}

int main(){
  int a,b,w;
  cin >> V;
  for(int i = 0 ; i < V-1 ; i++){
    cin >> a >> b >> w;
    G[a].push_back(Edge(b,w));
    G[b].push_back(Edge(a,w));
  }
  maxi = 0; fill(dist,dist+V,INF);
  getStart(0,0);
  memset(visited,false,sizeof(visited));
  visited[start] = true;
  cout << getTreeDiameter(start) << endl;
  return 0;
}
