#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 150
#define INF 1e9
 
bool used[MAX_V];
int cost[MAX_V][MAX_V], mincost[MAX_V], V;
 
int prim(){
    for(int i = 0 ; i < V ; i++){
	mincost[i] = INF;
	used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
 
    while(true){
	int v = -1;
	for(int u = 0 ; u < V ; u++){
	    if(!used[u] && (v == -1 || mincost[u] < mincost[v])){
		v = u;
	    }
	}
	if(v == -1) break;
	used[v] = true;
	res += mincost[v];
     
	for(int u = 0 ; u < V ; u++){
	    mincost[u] = min(mincost[u], cost[v][u]);
	}
    }
    return res;
}
 
int main(){
    int E, a, b, c;
 
    while(cin >> V >> E, (V|E)){
	fill(cost[0],cost[MAX_V],INF);
	for(int i = 0 ; i < E ; i++){
	    cin >> a >> b >> c;
	    cost[a][b] = cost[b][a] = c;
	}
	cout << prim() << endl;
    }
    return 0;
}
