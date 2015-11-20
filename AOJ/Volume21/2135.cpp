#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1011
#define INF 1e9
 
struct Edge{
    int u,v;
};
 
vector<int> G[MAX];
 
int bfs(int s,int t){
    queue<int> Q;
    Q.push(s);
    int dist[MAX];
    fill(dist,dist+MAX,INF);
    dist[s] = 0;
   
    while(!Q.empty()){
	int v = Q.front(); Q.pop();
	if(v == t) return dist[t];
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    if(dist[v] + 1 < dist[G[v][i]]){
		dist[G[v][i]] = dist[v] + 1;
		Q.push(G[v][i]);
	    }
	}
    }
    return INF;
}
 
int main(){
    int N,S,T,M;
    while(cin >> N,N){
	vector<Edge> e;
	cin >> S >> T >> M;
	S--; T--;
	for(int i = 0 ; i < MAX ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < M ; i++){
	    int u,v;
	    cin >> u >> v;
	    u--; v--;
	    e.push_back((Edge){u,v});
	    G[u].push_back(v);
	}
	int res,nc,num;
	res = nc = bfs(S,T);
	for(int i = 0 ; i < (int)e.size() ; i++){
	    for(int j = 0 ; j < N ; j++){
		G[j].clear();
	    }
	    swap(e[i].u,e[i].v);
	    for(int j = 0 ; j < (int)e.size() ; j++){
		G[e[j].u].push_back(e[j].v);
	    }
	    int r = bfs(S,T);
	    if(r < res){
		res = r;
		num = i+1;
	    }
	    swap(e[i].u,e[i].v);
	}
	if(res == nc){
	    cout << res << " " << 0 << endl;
	}else{
	    cout << res << " " << num << endl;
	}
    }
    return 0;
}
