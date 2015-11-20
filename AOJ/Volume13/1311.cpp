#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 101
#define MAX_E 1001
#define INF 1e9
 
struct Edge{
    int to,cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
 
struct P{
    int d,v,c;
    P(int d,int v,int c) : d(d),v(v),c(c) {}
    bool operator < (const P &p)const{
	if(c != p.c){
	    return c > p.c;
	}else{
	    return d > p.d;
	}
    }
};
 
int V,E,C;
int d[MAX_V][MAX_E];
vector<Edge> G[MAX_V];
 
void init(){
    for(int i = 0 ; i < MAX_V ; i++){
	G[i].clear();
    }
}
 
int dijkstra(){
    fill(d[0],d[0]+MAX_V*MAX_E,INF);
    d[0][0] = 0;
    priority_queue<P> Q;
    Q.push(P(0,0,0));
    while(!Q.empty()){
	P p = Q.top(); Q.pop();
	int v = p.v, c = p.c;
	if(d[v][c] < p.d) continue;
	if(v == V-1 && p.d <= C) return c;
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    if(d[v][c]+e.cost < d[e.to][c]){
		d[e.to][c] = d[v][c]+e.cost;
		Q.push(P(d[e.to][c],e.to,c));
	    }
	    if(d[v][c] < d[e.to][c+1]){
		d[e.to][c+1] = d[v][c];
		Q.push(P(d[e.to][c+1],e.to,c+1));
	    }
	}
    }
    return -1;
}
 
int main(){
    int f,t,c;
    while(cin >> V >> E >> C,V){
	init();
	for(int i = 0 ; i < E ; i++){
	    cin >> f >> t >> c;
	    f--; t--;
	    G[f].push_back(Edge(t,c));
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
