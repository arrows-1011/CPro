#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 110
#define INF 1e9
#define F first
#define S second
typedef pair<int,int> pii;
typedef pair<pii,int> State;
  
struct Edge{
    int to,cost;
    Edge(){}
    Edge(int to,int cost) : to(to),cost(cost) {}
};
  
int N,M,L,K,A,H;
bool l[MAX];
vector<Edge> G[MAX];
  
void init(){
    for(int i = 0 ; i < MAX ; i++){
	l[i] = false;
	G[i].clear();
    }
}
  
int dijkstra(){
    priority_queue<State,vector<State>,greater<State> > Q;
    Q.push(State(pii(0,A),M));
   
    int Time[MAX][MAX];
    fill(Time[0],Time[0]+MAX*MAX,INF);
    Time[A][M] = 0;
  
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.F.S, m = s.S;
	if(Time[v][m] < s.F.F) continue;
 
	if(v == H){
	    return Time[H][m];
	}
 
	if(l[v]){
	    for(int i = 1 ; i <= M-m ; i++){
		if(Time[v][m] + i < Time[v][m+i]){
		    Time[v][m+i] = Time[v][m] + i;
		    Q.push(State(pii(Time[v][m+i],v),m+i));
		}
	    }
	}
  
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    if(m - e.cost >= 0){
		if(Time[v][m] + e.cost < Time[e.to][m-e.cost]){
		    Time[e.to][m-e.cost] = Time[v][m] + e.cost;
		    Q.push(State(pii(Time[e.to][m-e.cost],e.to),m-e.cost));
		}
	    }
	}
    }
    return INF;
}
  
int main(){
    int a,b,c;
    while(cin >> N >> M >> L >> K >> A >> H, N){
	init();
	for(int i = 0 ; i < L ; i++){
	    cin >> a;
	    l[a] = true;
	}
	for(int i = 0 ; i < K ; i++){
	    cin >> a >> b >> c;
	    G[a].push_back(Edge(b,c));
	    G[b].push_back(Edge(a,c));
	}
	int res = dijkstra();
	if(res == INF){
	    cout << "Help!" << endl;
	}else{
	    cout << res << endl;
	}
    }
    return 0;
}
