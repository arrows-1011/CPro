#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100
#define MAX_V 2000
#define INF 1e9
 
int V,match[MAX_V];
vector<int> G[MAX_V];
bool used[MAX_V];
 
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
 
bool dfs(int v){
    used[v] = true;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	int u = G[v][i],w = match[u];
	if(w < 0 || (!used[w] && dfs(w))){
	    match[v] = u;
	    match[u] = v;
	    return true;
	}
    }
    return false;
}
 
int bipartite_matching(){
    int res = 0;
    memset(match,-1,sizeof(match));
    for(int v = 0 ; v < V ; v++){
	if(match[v] < 0){
	    memset(used,false,sizeof(used));
	    if(dfs(v)){ res++; }
	}
    }
    return res;
}
 
void init(){
    for(int i = 0 ; i < MAX_V ; i++){
	G[i].clear();
    }
}
 
int main(){
    int N,M,L,a,b,c;
    while(cin >> N >> M >> L, N){
	int d[MAX_N][MAX_N];
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		d[i][j] = (i != j ? INF : 0);  
	    }
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> a >> b >> c;
	    d[a][b] = d[b][a] = c;
	}
 
	int p[L],t[L];
	for(int i = 0 ; i < L ; i++){
	    cin >> p[i] >> t[i];
	}
	for(int i = 0 ; i < L ; i++){
	    for(int j = L-1 ; j > 0 ; j--){
		if(t[j] < t[j-1]){
		    swap(t[j],t[j-1]);
		    swap(p[j],p[j-1]);
		}
	    }
	}
	for(int k = 0 ; k < N ; k++){
	    for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	    }
	}
	init(); V = L;
	for(int i = 0 ; i < L ; i++){
	    for(int j = i+1 ; j < L ; j++){
		if(d[p[i]][p[j]] <= t[j]-t[i]){
		    add_edge(i,j+L);
		}
	    }
	}
	cout << L-bipartite_matching() << endl;
    }
    return 0;
}
