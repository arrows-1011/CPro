#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX_N 25
#define INF (1<<29)
  
struct Edge{
    int to,cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
  
int V,maxi,start,sum;
int dist[MAX_N];
bool leaf[MAX_N],visited[MAX_N];
vector<Edge> G[MAX_N];
  
void getStart(int v,int d){
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	Edge e = G[v][i];
	if(!leaf[e.to] && dist[e.to] == INF){
	    dist[e.to] = d + e.cost;
	    sum += e.cost*2;
	    getStart(e.to,d+e.cost);
	}
    }
}
 
int getTreeDiameter(int v){
    int res = 0;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	Edge e = G[v][i];
	if(!visited[e.to]){
	    visited[e.to] = true;
	    if(!leaf[e.to]){
		res = max(res,e.cost+getTreeDiameter(e.to));
	    }
	}
    }
    return res;
}
  
int main(){
    int N,a,b,c;
    while(cin >> N,N){
	for(int i = 0 ; i < N ; i++){
	    G[i].clear();
	    visited[i] = leaf[i] = false;
	}
	for(int i = 0 ; i < N-1 ; i++){
	    cin >> a >> b >> c; a--; b--;
	    G[a].push_back(Edge(b,c));
	    G[b].push_back(Edge(a,c));
	}
	for(int i = 1 ; i < N ; i++){
	    leaf[i] = (G[i].size() == 1);
	}
	sum = maxi = start = 0;
	fill(dist,dist+N,INF);
	dist[0] = 0; getStart(0,0);
	visited[start] = true;
	cout << sum-getTreeDiameter(start) << endl;
    }
    return 0;
}
