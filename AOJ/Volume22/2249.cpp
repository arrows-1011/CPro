#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10050
#define INF 1e9
 
struct P{
    int dist,cost,v;
    bool operator < (const P &p)const{
	if(dist != p.dist){
	    return dist > p.dist;
	}
	return cost > p.cost;
    }
};
 
int N,M;
vector<P> G[MAX];
 
int dijkstra(){
    int res = 0;
    bool visited[MAX] = {false};
    priority_queue<P> Q;
    Q.push((P){0,0,0});
 
    while(!Q.empty()){
	P p = Q.top(); Q.pop();
	int v = p.v;
	if(visited[v]) continue;
	visited[v] = true;
	res += p.cost;
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    P e = G[v][i];
	    Q.push((P){p.dist+e.dist,e.cost,e.v});
	}
    }
    return res;
}
 
int main(){
    int u,v,d,c;
    while(cin >> N >> M, N){
	for(int i = 0 ; i < N ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> u >> v >> d >> c;
	    u--; v--;
	    G[u].push_back((P){d,c,v});
	    G[v].push_back((P){d,c,u});
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
