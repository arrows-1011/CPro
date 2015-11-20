#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int INF = 1<<27;
const int MAX = 51;
 
int dis_d[MAX][MAX],in,s,d,G[MAX];
int min_d[MAX];
bool used[MAX];
 
int prim(){
    for(int i = 0 ; i < d ; i++){
	min_d[i] = INF;
	used[i] = false;
    }
 
    min_d[0] = 0;
    int res = 0;
 
    while(true){
	int v = -1;
 
	for(int u = 0 ; u < d ; u++){
	    if(!used[u] && (v == -1 || min_d[u] < min_d[v])) v = u;
	}
 
	if(v == -1) break;
	used[v] = true;
	res += min_d[v];
 
	for(int u = 0 ; u < d ; u++){
	    min_d[u] = min(min_d[u],dis_d[v][u]);
	}
    }
 
    return res;
}
 
int main(){
    while(cin >> s >> d , s + d){
	fill(G,G+MAX,INF);
 
	for(int i = 0 ; i < s ; i++){
	    for(int j = 0 ; j < d ; j++){
		cin >> in;
		if(!in) continue;
		G[j] = min(G[j],in);
	    }
	}
	fill(dis_d[0],dis_d[MAX],INF);
 
	for(int i = 0 ; i < d ; i++){
	    dis_d[i][d] = dis_d[d][i] = G[i];
	}    
 
	for(int i = 0 ; i < d-1 ; i++){
	    for(int j = i + 1 ; j < d ; j++){
		cin >> in;
		if(!in) continue;
		dis_d[i][j] = dis_d[j][i] = in;
	    }
	}       
	d++;
	cout << prim() << endl;
    }
    return 0;
}
