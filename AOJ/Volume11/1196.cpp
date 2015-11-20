#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
#define MAX_N 810
typedef vector<int> Vec;
typedef pair<int,int> pii;
 
struct Edge{
    int to,cost;
    Edge(int to,int cost) :
	to(to),cost(cost) {}
};
 
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
 
int N;
Graph G;
bool leaf[MAX_N];
 
Vec dijkstra(int s){
    Vec dist(N,INF);
    dist[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii> > Q;
    Q.push(pii(0,s));
    while(!Q.empty()){
	pii p = Q.top(); Q.pop();
	int v = p.second;
	if(dist[v] < p.first){
	    continue;
	}
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge &e = G[v][i];
	    if(dist[v] + e.cost < dist[e.to]){
		dist[e.to] = dist[v] + e.cost;
		Q.push(pii(dist[e.to],e.to));
	    }
	}
    }
    return dist;
}
 
int getFarthestPoint(int v){
    Vec vec = dijkstra(v);
    int resv = -1, max = -1;
    for(int i = 0 ; i < N ; i++){
	if(max < vec[i] && vec[i] != INF){
	    max = vec[i];
	    resv = i;
	}
    }
    return resv;
}
 
int getTreeDiameter(){
    int v = -1;
    for(int i = 0 ; i < N ; i++){
	if(!leaf[i]){
	    v = i;
	    break;
	}
    }
    int v1 = getFarthestPoint(v);
    int v2 = getFarthestPoint(v1);
    Vec d = dijkstra(v2);
    int res = 0;
    for(int i = 0 ; i < (int)d.size() ; i++){
	if(d[i] != INF){
	    res = max(res,d[i]);
	}
    }
    return res;
}
 
void init(){
    for(int i = 0 ; i < (int)G.size() ; i++){
	G[i].clear();
    }
    G.clear();
    G.resize(N);
}
 
int main(){
    while(cin >> N, N){
	init();
	int sum = 0;
	Vec p(N-1);
	for(int i = 0 ; i < N-1 ; i++){
	    cin >> p[i]; p[i]--;
	}
	Graph G2(N);
	for(int i = 0 ; i < N-1 ; i++){
	    int d; cin >> d; sum += d;
	    G2[p[i]].push_back(Edge(i+1,d));
	    G2[i+1].push_back(Edge(p[i],d));
	}
	memset(leaf,false,sizeof(leaf));
	for(int i = 0 ; i < (int)G2.size() ; i++){
	    if(G2[i].size() == 1){
		leaf[i] = true;
	    }
	}
	for(int i = 0 ; i < (int)G2.size() ; i++){
	    if(!leaf[i]){
		for(int j = 0 ; j < (int)G2[i].size() ; j++){
		    if(!leaf[G2[i][j].to]){
			G[i].push_back(G2[i][j]);
			sum += G2[i][j].cost;
		    }
		}
	    }
	}
	cout << sum-getTreeDiameter() << endl;
    }
    return 0;
}
