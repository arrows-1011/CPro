#include <bits/stdc++.h>

using namespace std;

#define MAX_V 51
#define MAX_C 310
#define INF 1e9

struct Edge{
  int to,cost,time;
  Edge(int to,int cost,int time) :
    to(to),cost(cost),time(time) {}
};

struct State{
  int v,cost,time;
  State(int v,int cost,int time) :
    v(v),cost(cost),time(time) {}

  bool operator > (const State &s)const{
    if(time != s.time){ return time > s.time; }
    return cost > s.cost;
  }
};

int N,C,V;
vector<Edge> G[MAX_V];

int dijkstra(){
  int d[MAX_V][MAX_C];
  fill(d[0],d[0]+MAX_V*MAX_C,INF);
  d[0][C] = 0;
  priority_queue<State,vector<State>,greater<State>> Q;
  Q.push(State(0,C,0));
  while(!Q.empty()){
    State s = Q.top(); Q.pop();
    int v = s.v,c = s.cost,t = s.time;
    if(d[v][c] < t){ continue; }
    if(v == N-1){ return d[v][c]; }
    for(int i = 0 ; i < (int)G[v].size() ; i++){
      Edge e = G[v][i];
      int nc = c-e.cost;
      if(nc < 0){ continue; }
      if(d[v][c] + e.time < d[e.to][nc]){
	d[e.to][nc] = d[v][c] + e.time;
	Q.push(State(e.to,nc,d[e.to][nc]));
      }
    }
  }
  return -1;
}

int main(){
  cin >> N >> C >> V;
  vector<int> S(V),T(V),Y(V),M(V);
  for(int i = 0 ; i < V ; i++){ cin >> S[i]; S[i]--; }
  for(int i = 0 ; i < V ; i++){ cin >> T[i]; T[i]--; }
  for(int i = 0 ; i < V ; i++){ cin >> Y[i]; }
  for(int i = 0 ; i < V ; i++){ cin >> M[i]; }
  for(int i = 0 ; i < V ; i++){
    G[S[i]].push_back(Edge(T[i],Y[i],M[i]));
  }
  cout << dijkstra() << endl;
  return 0;
}
