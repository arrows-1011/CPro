#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 310
#define INF 1e9
 
struct edge{
    int to,cap,cost,rev;
    edge(int to,int cap,int cost,int rev) :
	to(to),cap(cap),cost(cost),rev(rev) {}
};
 
vector<edge> G[MAX_V];
int dist[MAX_V],prevv[MAX_V],preve[MAX_V];
 
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,G[to].size()));
    G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}
 
  
int min_cost_flow(int s,int t,int f){
    int res = 0;
    while(f > 0){
	fill(dist,dist+MAX_V,INF); dist[s] = 0;
	bool update = true;
	while(update){
	    update = false;
	    for(int v = 0 ; v < MAX_V ; v++){
		if(dist[v] == INF) continue;
		for(int i = 0 ; i < (int)G[v].size() ; i++){
		    edge &e = G[v][i];
		    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
			dist[e.to] = dist[v] + e.cost;
			prevv[e.to] = v; preve[e.to] = i; update = true;
		    }
		}
	    }
	}
	if(dist[t] == INF) return -1;
	int d = f;
	for(int v = t ; v != s ; v = prevv[v]){
	    d = min(d,G[prevv[v]][preve[v]].cap);
	}
	f -= d; res += d * dist[t];
	for(int v = t ; v != s ; v = prevv[v]){
	    edge &e = G[prevv[v]][preve[v]];
	    e.cap -= d; G[v][e.rev].cap += d;
	}
    }
    return res;
}
 
int main(){
    int N,p[MAX_V];
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> p[i];
    }
    int s = 2*N+1,t = s+1;
    for(int i = 0 ; i < N ; i++){
	add_edge(s,i+1,1,0);
	add_edge(N+i+1,t,1,0);
    }
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    if(i+1 == p[j]) continue;
	    add_edge(i+1,N+j+1,1,p[j]*abs(i-j));
	}
    }
    cout << min_cost_flow(s,t,N) << endl;
    return 0;
}
