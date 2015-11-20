#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 550
#define INF 1e8
 
struct edge{
    int to,cap,cost,rev;
    edge(int to,int cap,int cost,int rev) :
	to(to),cap(cap),cost(cost),rev(rev) {}
};
 
vector<edge> G[MAX_V];
int dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
 
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back(edge(to,cap,cost,G[to].size()));
    G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}
 
int min_cost_flow(int s,int t,int f){
    int res = 0;
    while(f > 0){
	fill(dist,dist+MAX_V,INF);
	dist[s] = 0;
	bool update = true;
	while(update){
	    update = false;
	    for(int v = 0 ; v < MAX_V ; v++){
		if(dist[v] == INF) continue;
		for(int i = 0 ; i < (int)G[v].size() ; i++){
		    edge &e = G[v][i];
		    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
			dist[e.to] = dist[v] + e.cost;
			prevv[e.to] = v;
			preve[e.to] = i;
			update = true;
		    }
		}
	    }
	}
     
	if(dist[t] == INF){
	    return -1;
	}
     
	int d = f;
	for(int v = t ; v != s ; v = prevv[v]){
	    d = min(d,G[prevv[v]][preve[v]].cap);
	}
	f -= d;
	res += d * dist[t];
	for(int v = t ; v != s ; v = prevv[v]){
	    edge &e = G[prevv[v]][preve[v]];
	    e.cap -= d;
	    G[v][e.rev].cap += d;
	}
    }
    return res;
}
 
int main(){
    int N;
    while(cin >> N, N){
	for(int i = 0 ; i < MAX_V ; i++){
	    G[i].clear();
	}
	int a,b,w;
	for(int i = 0 ; i < N ; i++){
	    cin >> a >> b >> w;
	    add_edge(a-1,b,1,-w);
	}
	for(int i = 0 ; i < 365 ; i++){
	    add_edge(i,i+1,2,0);
	}
	cout << -min_cost_flow(0,365,2) << endl;
    }
    return 0;
}
