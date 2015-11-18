#include <bits/stdc++.h>

using namespace std;

struct Edge{
  int to,weight;
  Edge(int to,int weight) :
    to(to),weight(weight) {}
};

typedef vector<int> Vec;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int visit(const Graph &g,Graph &T,int u,int v){
  if(T[u][v].weight >= 0){
    return T[u][v].weight;
  }
  T[u][v].weight = g[u][v].weight;
  int w = T[u][v].to;
  for(int i = 0 ; i < (int)T[w].size() ; i++){
    if(T[w][i].to == u) continue;
    T[u][v].weight = max(T[u][v].weight,visit(g,T,w,i)+g[u][v].weight);
  }
  return T[u][v].weight;
}

Vec solve(const Graph &g){
  int N = g.size();
  Graph T(g);
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < (int)T[i].size() ; j++){
      T[i][j].weight = -1;
    }
  }
  for(int i = 0 ; i < N ; i++){
    for(int j = 0 ; j < (int)T[i].size() ; j++){
      if(T[i][j].weight < 0){
        T[i][j].weight = visit(g,T,i,j);
      }
    }
  }
  Vec res(N);
  for(int i = 0 ; i < N ; i++){
    int max = 0;
    for(int j = 0 ; j < (int)T[i].size() ; j++){
      max = std::max(max,T[i][j].weight);
    }
    res[i] = max;
  }
  return res;
}

int main(){
  int N,a,b,c;
  cin >> N;
  Graph g(N);
  for(int i = 0 ; i < N-1 ; i++){
    cin >> a >> b >> c;
    g[a].push_back(Edge(b,c));
    g[b].push_back(Edge(a,c));
  }
  Vec v = solve(g);
  for(int i = 0 ; i < N ; i++){
    cout << v[i] << endl;
  }
  return 0;
}
