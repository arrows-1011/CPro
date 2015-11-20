#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
#define INF 1e9
 
struct State{
    int v,s;
    State(int v,int s) : v(v),s(s) {}
};
 
int N,W[2][MAX];
 
int bfs(int s){
    queue<State> Q;
    Q.push(State(0,s));
    bool visited[2][MAX];
    memset(visited,false,sizeof(visited));
    int dist[2][MAX];
    fill(dist[0],dist[0]+MAX*2,INF);
    dist[s][0] = 0;
   
    while(!Q.empty()){
	int v = Q.front().v; 
	int s = Q.front().s;
	Q.pop();
 
	if(visited[s][v]) return INF;
	visited[s][v] = true;
 
	int cur = v;
	if(W[s][v] == 1){
	    for(int i = v+1 ; i < N ; i++){
		if(W[s][i] != 1) break;
		dist[s][i] = min(dist[s][i],dist[s][v]);
		cur = i;
	    }
	}else if(W[s][v] == 2){
	    for(int i = v-1 ; i >= 0 ; i--){
		cur = i;
		dist[s][i] = min(dist[s][i],dist[s][v]);
		if(W[s][i] != 2) break;
	    }
	}
    
	if(cur == N-1){
	    return dist[s][v];
	}
	v = cur;
	for(int i = 0 ; i < 3 ; i++){
	    if(dist[s][v] + 1 < dist[!s][v+i]){
		dist[!s][v+i] = dist[s][v] + 1;
		Q.push(State(v+i,!s));
	    }   
	}
    }
    return INF;
}
 
int main(){
    while(cin >> N, N){
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < N ; j++){
		cin >> W[i][j];
	    }
	}
	int res = min(bfs(0),bfs(1));
	if(res == INF){
	    cout << "NA" << endl;
	}else{
	    cout << res << endl;
	}
    }
    return 0;
}
