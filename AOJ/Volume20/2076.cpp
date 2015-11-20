#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 110
#define MAX_V 310
#define INF 1e9
 
struct Edge{ int to,cap,rev; };
 
vector<Edge> G[MAX_V];
int level[MAX_V],iter[MAX_V];
 
void add_edge(int from,int to,int cap){
    G[from].push_back((Edge){to,cap,G[to].size()});
    G[to].push_back((Edge){from,0,G[from].size()-1});
}
 
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while(!Q.empty()){
	int v = Q.front(); Q.pop();
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge &e = G[v][i];
	    if(e.cap > 0 && level[e.to] < 0){
		level[e.to] = level[v] + 1;
		Q.push(e.to);
	    }
	}
    }
}
 
int dfs(int v,int t,int f){
    if(v == t) return f;
    for(int &i = iter[v] ; i < (int)G[v].size() ; i++){
	Edge &e = G[v][i];
	if(e.cap > 0 && level[v] < level[e.to]){
	    int d = dfs(e.to,t,min(f,e.cap));
	    if(d > 0){
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}
 
int max_flow(int s,int t){
    int flow = 0;
    for(;;){
	bfs(s);
	if(level[t] < 0) return flow;
	memset(iter,0,sizeof(iter));
	int f;
	while((f = dfs(s,t,INF)) > 0){
	    flow += f;
	}
    }
}
 
int main(){
    int N,M,L,a,b,c;
    while(cin >> N >> M >> L){
	for(int i = 0 ; i < MAX_V ; i++){
	    G[i].clear();
	}
	int d[MAX_N][MAX_N];
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j){ d[i][j] = 0; }
		else{ d[i][j] = INF; }
	    }
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> a >> b >> c; a--; b--;
	    d[a][b] = d[b][a] = c;
	}
	for(int k = 0 ; k < N ; k++){
	    for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	    }
	}
	int P[MAX_N],K[MAX_N];
	for(int i = 0 ; i < N ; i++){
	    cin >> P[i];
	}
	for(int i = 0 ; i < N ; i++){
	    cin >> K[i];
	}
	int S = N*2,T = S+1;
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(d[i][j] < L){
		    add_edge(i,j+N,P[i]);
		}
	    }
	}
	for(int i = 0 ; i < N ; i++){
	    add_edge(S,i,P[i]);
	    add_edge(i+N,T,K[i]);
	}
	cout << max_flow(S,T) << endl;
    }
    return 0;
}
