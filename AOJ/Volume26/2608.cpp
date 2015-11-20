#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 100000
#define INF (1<<29)
typedef long long ll;
 
void bfs(int s,int *d,ll *cnt,vector<int> G[MAX_V]){
    queue<int> Q; Q.push(s);
    memset(cnt,0,sizeof(cnt));
    fill(d,d+MAX_V,INF);
    d[s] = 0;
    cnt[d[s]]++;
    while(!Q.empty()){
	int v = Q.front(); Q.pop();
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    int to = G[v][i];
	    if(d[v] + 1 < d[to]){
		d[to] = d[v] + 1;
		cnt[d[to]]++;
		Q.push(to);
	    }
	}
    }
}
 
int main(){
    int V,E,S,T,x,y;
    int ds[MAX_V],dt[MAX_V];
    ll cs[MAX_V],ct[MAX_V];
    vector<int> G[MAX_V];
    cin >> V >> E >> S >> T;
    S--; T--;
    for(int i = 0 ; i < E ; i++){
	cin >> x >> y; x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
   
    bfs(S,ds,cs,G); 
    bfs(T,dt,ct,G);
   
    ll ans = 0LL;
    int min_dist = ds[T];
    for(int i = 0 ; i < V ; i++){
	int j = min_dist-2-i;
	ans += (j >= 0 ? cs[i]*ct[j] : 0);
    }
    cout << ans << endl;
    return 0;
}
