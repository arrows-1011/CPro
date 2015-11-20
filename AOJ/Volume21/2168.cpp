#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX_V 500
#define INF (1<<29)
  
struct edge{ int to,cap,rev; };
  
vector<edge> G[MAX_V];
bool used[MAX_V];
  
void add_edge(int from,int to,int cap){
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}
  
int dfs(int v,int t,int f){
    if(v == t) return f;
    used[v] = true;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	edge &e = G[v][i];
	if(!used[e.to] && e.cap > 0){
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
	memset(used,0,sizeof(used));
	int f = dfs(s,t,INF);
	if(f == 0) return flow;
	flow += f;
    }
}
  
void init(){
    for(int i = 0 ; i < MAX_V ; i++){
	G[i].clear();
    }
}
  
int main(){
    int H,W,C,M,Nw,Nc,Nm;
    while(cin >> H >> W >> C >> M >> Nw >> Nc >> Nm, H != -1){
	int k,a;
	init();
	for(int i = 0 ; i < W ; i++){
	    cin >> k;
	    while(k--){
		cin >> a; a--;
		add_edge(a,H+i,1);
	    }
	}
	for(int i = 0 ; i < W ; i++){
	    add_edge(H+i,H+W+i,1);
	}
     
	for(int i = 0 ; i < C ; i++){
	    cin >> k;
	    while(k--){
		cin >> a; a--;
		add_edge(H+W+a,H+W*2+i,1);
	    }
	}
	for(int i = 0 ; i < C ; i++){
	    add_edge(H+W*2+i,H+W*2+C+i,1);
	}
 
	for(int i = 0 ; i < M ; i++){
	    cin >> k;
	    while(k--){
		cin >> a; a--;
		add_edge(H+W*2+C+a,H+W*2+C*2+i,1);
	    }
	}
     
	int S = H+W*2+C*2+M,T = S+1;
	for(int i = 0 ; i < H ; i++){
	    add_edge(S,i,1);
	}
	for(int i = 0 ; i < M ; i++){
	    add_edge(H+W*2+C*2+i,T,1);
	}
 
	int Wnot = T+1,Wnot2 = Wnot+1;
	for(int i = 0 ; i < H ; i++){
	    add_edge(i,Wnot,1);
	}
	add_edge(Wnot,Wnot2,Nw);
	for(int i = 0 ; i < C ; i++){
	    add_edge(Wnot2,H+W*2+i,1);
	}
 
	int Cnot = Wnot2+1,Cnot2 = Cnot+1;
	for(int i = 0 ; i < W ; i++){
	    add_edge(H+W+i,Cnot,1);
	}
	add_edge(Cnot,Cnot2,Nc);
	for(int i = 0 ; i < M ; i++){
	    add_edge(Cnot2,H+W*2+C*2+i,1);
	}
 
	int Mnot = Cnot2+1;
	for(int i = 0 ; i < C ; i++){
	    add_edge(H+W*2+C+i,Mnot,1);
	}
	add_edge(Mnot,T,Nm);
	cout << max_flow(S,T) << endl;
    }
    return 0;
}
