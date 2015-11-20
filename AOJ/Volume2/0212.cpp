#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 120
#define INF 1e9
 
struct Edge{
    int to,cost;
    Edge(int t,int c) : to(t),cost(c) {}
};
 
struct State{
    int cost,v,tic;
    State(int c,int v,int t) : cost(c),v(v),tic(t) {}
    bool operator < (const State &s)const{
	return cost > s.cost;
    }
};
 
int C,V,E,src,dst;
vector<Edge> G[MAX];
 
int dijkstra(){
    priority_queue<State> Q;
    Q.push(State(0,src,C));
    int dist[MAX][11];
    fill(dist[0],dist[0]+MAX*11,INF);
    dist[src][C] = 0;
   
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v,t = s.tic;
	if(dist[v][t] < s.cost) continue;
	if(v == dst) return dist[v][t];
     
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    if(dist[v][t] + e.cost < dist[e.to][t]){
		dist[e.to][t] = dist[v][t] + e.cost;
		Q.push(State(dist[e.to][t],e.to,t));
	    }
	    if(t > 0){
		if(dist[v][t] + e.cost/2 < dist[e.to][t-1]){
		    dist[e.to][t-1] = dist[v][t] + e.cost/2;
		    Q.push(State(dist[e.to][t-1],e.to,t-1));
		}
	    }
	}
    }
}
 
int main(){
    while(cin >> C >> V >> E >> src >> dst, C){
	src--; dst--;
	for(int i = 0 ; i < V ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < E ; i++){
	    int a,b,c;
	    cin >> a >> b >> c; a--; b--;
	    G[a].push_back(Edge(b,c));
	    G[b].push_back(Edge(a,c));
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
