#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 101
#define INF INT_MAX/4
 
int G[MAX][MAX], N;
 
int dijkstra(int a,int b){
    bool used[MAX];
    int cost[MAX];
    memset(used,false,sizeof(used));
    fill(cost, cost+N, INF);
 
    cost[a] = 0;
    while(true){
	int v = -1;
	for(int u = 0 ; u < N ; u++){
	    if(!used[u] && (v == -1 || cost[u] < cost[v])){
		v = u;
	    }
	}
 
	if(v == -1) break;
	used[v] = true;
 
	for(int u = 0 ; u < N ; u++){
	    cost[u] = min(cost[u],cost[v]+G[v][u]);
	}
    }
 
    return cost[b];
}
 
int main(){
    int K, num, a, b, c;
 
    while(scanf("%d%d",&N,&K), (N | K)){
	fill(G[0], G[N], INF);
 
	while(K--){  
	    scanf("%d",&num);
	    if(num){
		cin >> a >> b >> c;
		a--, b--;
		if(G[a][b] > c){
		    G[a][b] = G[b][a] = c;
		}
	    }else{
		cin >> a >> b; a--, b--;
		int val = dijkstra(a,b);
		if(val != INF){
		    printf("%d\n",val);
		}else{
		    puts("-1");
		}
	    }
	}
    }
    return 0;
}
