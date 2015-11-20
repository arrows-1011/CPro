#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 334
#define MAX_L 17
#define INF 1e9
 
struct edge{
    int to,cost;
};
 
struct State{
    int cost,v,S;
    bool operator < (const State &s)const{
	return cost > s.cost;
    }
};
 
int N,M,L,S,T,restv[MAX_L],reste[MAX_L];
vector<edge> G[MAX_L];
int dist[1<<MAX_L][MAX_L];
 
string bit(int S){
    string res;
    for(int i = 0 ; i < L ; i++){
	if((S >> i) & 1) res += '1';
	else res += '0';
    }
    return res;
}
 
int dijkstra(){
    priority_queue<State> Q;
    Q.push((State){0,L,0});
    int ans = 0;
    for(int i = 0 ; i < (1<<L) ; i++){
	for(int j = 0 ; j <= L ; j++){
	    dist[i][j] = INF;
	}
    }
    dist[0][L] = 0;
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v;
	if(s.cost <= T && v == L){
	    ans = max(ans,__builtin_popcount(s.S));
	}
	if(s.cost >= T) continue;
	if(dist[s.S][v] < s.cost) continue;
	if(v != L){
	    if(!((s.S >> v) & 1)){
		int next = s.S | (1<<v);
		if(dist[s.S][v] + reste[v] < dist[next][v]){
		    dist[next][v] = dist[s.S][v] + reste[v];
		    Q.push((State){dist[next][v],v,next});
		}
	    }
	}
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    edge &e = G[v][i];
	    if(dist[s.S][v] + e.cost < dist[s.S][e.to]){
		dist[s.S][e.to] = dist[s.S][v] + e.cost;
		Q.push((State){dist[s.S][e.to],e.to,s.S});
	    }
	}
    }
    return ans;
}
 
int main(){
    while(cin >> N >> M >> L >> S >> T, N){
	int d[MAX][MAX];
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j){
		    d[i][j] = 0;
		}else{
		    d[i][j] = INF;
		}
	    }
	}
	for(int i = 0 ; i < MAX_L ; i++){
	    G[i].clear();
	}
	S--;
	for(int i = 0 ; i < M ; i++){
	    int a,b,c;
	    cin >> a >> b >> c;
	    a--; b--;
	    d[a][b] = d[b][a] = c;
	}
	for(int k = 0 ; k < N ; k++){
	    for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
		}
	    }
	}
	int restv[MAX_L];
	for(int i = 0 ; i < L ; i++){
	    cin >> restv[i] >> reste[i];
	    restv[i]--;
	}
	restv[L] = S; reste[L] = 0;
	for(int i = 0 ; i <= L ; i++){
	    for(int j = i+1 ; j <= L ; j++){
		int time = d[restv[i]][restv[j]];
		if(time == INF) continue;
		G[i].push_back((edge){j,time});
		G[j].push_back((edge){i,time});
	    }
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
