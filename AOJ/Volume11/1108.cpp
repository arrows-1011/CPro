#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10
 
struct Edge{
    int dst,weight;
    Edge(int dst,int weight) : dst(dst),weight(weight) {}
};
 
int V,E;
int ans_dist;
vector<int> ans;
vector<Edge> G[MAX];
bool visited[MAX][MAX];
 
void dfs(int v,int dist,vector<int> &routes){
    if(ans_dist < dist){
	ans_dist = dist;
	ans = routes;
    }
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	int to = G[v][i].dst;
	if(visited[v][to]) continue;
	visited[v][to] = visited[to][v] = true;
	routes.push_back(to+1);
	dfs(to,dist+G[v][i].weight,routes);
	routes.pop_back();
	visited[v][to] = visited[to][v] = false;
    }
}
 
int main(){
    int a,b,c;
    while(cin >> V >> E, (V | E)){
	ans_dist = 0; ans.clear();
	for(int i = 0 ; i < V ; i++){
	    G[i].clear();
	}
	memset(visited,false,sizeof(visited));
	for(int i = 0 ; i < E ; i++){
	    cin >> a >> b >> c; a--, b--;
	    G[a].push_back(Edge(b,c));
	    G[b].push_back(Edge(a,c));
	}
	vector<int> vec;
	for(int i = 0 ; i < V ; i++){
	    vec.push_back(i+1);
	    dfs(i,0,vec);
	    vec.pop_back();
	}
	cout << ans_dist << endl;
	for(int i = 0 ; i < (int)ans.size() ; i++){
	    if(i) cout << " ";
	    cout << ans[i];
	}
	cout << endl;
    }
    return 0;
}
