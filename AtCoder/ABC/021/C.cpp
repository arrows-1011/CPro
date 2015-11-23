#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
#define INF (1<<29)
#define MOD 1000000007
 
int main(){
    int N,a,b,M,x,y;
    vector<int> G[MAX];
    cin >> N >> a >> b >> M;
    a--; b--;
    for(int i = 0 ; i < M ; i++){
	cin >> x >> y;
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }
  
    int d[MAX],dp[MAX];
    for(int i = 0 ; i < MAX ; i++){
	d[i] = INF; dp[i] = 0;
    }
    d[a] = 0; dp[a] = 1;
    queue<int> Q; Q.push(a);
  
    while(!Q.empty()){
	int v = Q.front(); Q.pop();
	if(v == b) continue;
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    int to = G[v][i];
	    if(d[v]+1 < d[to]){
		d[to] = d[v]+1;
		dp[to] = dp[v];
		Q.push(to);
	    }else if(d[v]+1 == d[to]){
		dp[to] += dp[v];
		dp[to] %= MOD;
	    }
	}
    }
    cout << dp[b] << endl;
    return 0;
}
