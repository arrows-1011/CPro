#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 301
#define INF (1<<29)
typedef pair<int,int> P;
 
struct edge{ int to,cap,cost,rev; };
 
int V,h[MAX_V];
vector<edge> G[MAX_V],tmp[MAX_V];
int dist[MAX_V],prevv[MAX_V],preve[MAX_V];
 
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
 
int min_cost_flow(int s,int t,int f){
    int res = 0;
    fill(h, h + V, 0);
    while(f > 0){
	priority_queue<P, vector<P>, greater<P> > Q;
	fill(dist, dist + V, INF);
	dist[s] = 0;
	Q.push(P(0,s));
	while(!Q.empty()){
	    P p = Q.top(); Q.pop();
	    int v = p.second;
	    if(dist[v] < p.first) continue;
	    for(int i = 0 ; i < (int)G[v].size() ; i++){
		edge &e = G[v][i];
		if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
		    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
		    prevv[e.to] = v;
		    preve[e.to] = i;
		    Q.push(P(dist[e.to],e.to));
		}
	    }
	}
	if(dist[t] == INF) return -1;
    
	for(int v = 0 ; v < V ; v++){
	    h[v] += dist[v];
	}
    
	int d = f;
	for(int v = t ; v != s ; v = prevv[v]){
	    d = min(d,G[prevv[v]][preve[v]].cap);
	}
	f -= d;
	res += d*h[t];
	for(int v = t ; v != s ; v = prevv[v]){
	    edge &e = G[prevv[v]][preve[v]];
	    e.cap -= d;
	    G[v][e.rev].cap += d;
	}
    }
    return res;
}
 
int main(){
    int N,M,a,b,c;
    cin >> N >> M; V = N;
    for(int i = 0 ; i < M ; i++){
	cin >> a >> b >> c; a--; b--;
	add_edge(a,b,1,c);
	add_edge(b,a,1,c);
    }
    int res = INF;
    for(int i = 1 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    tmp[j] = G[j];
	}
	int x = min_cost_flow(0,i,2);
	if(x >= 0) res = min(res,x);
	for(int j = 0 ; j < N ; j++){
	    G[j] = tmp[j];
	}
    }
    cout << (res == INF ? -1 : res) << endl;
    return 0;
}
