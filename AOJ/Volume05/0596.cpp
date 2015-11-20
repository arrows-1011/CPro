#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 5010
#define INF 1e9
#define F first
#define S second
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
  
int N,K;
pii taxi[MAX];
vector<int> G[MAX];
int cost[MAX][MAX];
 
int dijkstra(){
    priority_queue<piii,vector<piii>,greater<piii> > Q;
    Q.push(piii(pii(0,0),0));
    fill(cost[0],cost[0]+MAX*MAX,INF);
    cost[0][0] = 0;
 
    while(!Q.empty()){
	piii p = Q.top(); Q.pop();
	int v = p.F.S, r = p.S;
	if(cost[v][r] < p.F.F) continue;
 
	if(r > 0){
	    for(int i = 0 ; i < (int)G[v].size() ; i++){
		int to = G[v][i];
		if(cost[v][r] < cost[to][r-1]){
		    cost[to][r-1] = cost[v][r];
		    Q.push(piii(pii(cost[to][r-1],to),r-1));
		}
	    }
	}
	pii t = taxi[v];
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    int to = G[v][i];
	    if(cost[v][r] + t.F < cost[to][t.S-1]){
		cost[to][t.S-1] = cost[v][r] + t.F;
		Q.push(piii(pii(cost[to][t.S-1],to),t.S-1));
	    }
	}
    }
    return *min_element(cost[N-1],cost[N-1]+N);
}
 
int main(){
    int C,R,A,B;
    cin >> N >> K;
    for(int i = 0 ; i < N ; i++){
	cin >> C >> R;
	taxi[i] = pii(C,R);
    }
    for(int i = 0 ; i < K ; i++){
	cin >> A >> B; A--; B--;
	G[A].push_back(B);
	G[B].push_back(A);
    }
    cout << dijkstra() << endl;
    return 0;
}
