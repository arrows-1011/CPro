#include <bits/stdc++.h>

using namespace std;

#define MAX_V 1000
#define INF 1e9

int cost[MAX_V][MAX_V]; //cost[u][v]は辺e=(u,v)のコスト(存在しない場合はINF)
int mincost[MAX_V];     //集合Xからの辺の最小コスト
bool used[MAX_V];       //頂点iがXに含まれているか
int V;                  //超点数

/*
  O(V^2)
  Data setの最初にinitする。
*/

void init(){
    for(int i = 0 ; i < V ; i++){
	mincost[i] = INF;
	used[i] = false;
	for(int j = 0 ; j < V ; j++){
	    cost[i][j] = INF;
	}
    }
}

int prim(){
    mincost[0] = 0;
    int res = 0;
  
    while(true){
	int v = -1;
	//Xに属さない頂点のうちXからの辺のコストが最小になる頂点を探す
	for(int u = 0 ; u < V ; u++){
	    if(!used[u] && (v == -1 || mincost[u] < mincost[v])){
		v = u;
	    }
	}
	if(v == -1) break;
	used[v] = true;        //頂点Vを集合Xに追加
	res += mincost[v];     //辺のコストを加える

	for(int u = 0 ; u < V ; u++){
	    mincost[u] = min(mincost[u],cost[v][u]);
	}
    }
    return res;
}
