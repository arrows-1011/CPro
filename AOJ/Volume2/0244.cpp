#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
#define INF 1e9
typedef pair<int,int> pii;
typedef pair<pii,int> State;
 
struct Edge{
    int to,cost;
    Edge() {}
    Edge(int to,int cost) : to(to),cost(cost) {}
};
 
int V,E;
vector<Edge> G[MAX];
 
int dijkstra(){
    priority_queue<State,vector<State>,greater<State> > Q;
    Q.push(State(pii(0,0),0));
    int dp[MAX][2];
    fill(dp[0],dp[0]+MAX*2,INF);
    dp[0][0] = 0;
 
    while(!Q.empty()){
	State p = Q.top(); Q.pop();
	int v = p.first.second,s = p.second;
 
	if(dp[v][s] < p.first.first) continue;
 
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    if(dp[v][s] + G[v][i].cost < dp[G[v][i].to][s]){
		dp[G[v][i].to][s] = dp[v][s] + G[v][i].cost;
		Q.push(State(pii(dp[G[v][i].to][s],G[v][i].to),s));
	    }
	    if(s) continue;
	    int d = G[v][i].to;
	    for(int j = 0 ; j < (int)G[d].size() ; j++){
		if(dp[v][0] < dp[G[d][j].to][1]){
		    dp[G[d][j].to][1] = dp[v][0];
		    Q.push(State(pii(dp[G[d][j].to][1],G[d][j].to),1));
		}
	    }
	}
    }
    return min(dp[V-1][0],dp[V-1][1]);
}
 
int main(){
    int a,b,c;
    while(cin >> V >> E, V){
	for(int i = 0 ; i < V ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < E ; i++){
	    cin >> a >> b >> c;
	    a--, b--;
	    G[a].push_back(Edge(b,c));
	    G[b].push_back(Edge(a,c));
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
