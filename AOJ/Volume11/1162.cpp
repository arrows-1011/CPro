#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 35
#define INF 1e9
#define F first
#define S second
typedef pair<double,int> pdi;
typedef pair<int,int> pii;
typedef pair<pdi,pii> State;
  
struct Edge{
    int to,d,c;
    Edge(int to,int d,int c) : to(to),d(d),c(c) {}
};
  
int N,M,s,g;
vector<Edge> G[MAX];
  
double dijkstra(){
    priority_queue<State,vector<State>,greater<State> > Q;
    Q.push(State(pdi(0,s),pii(1,N)));
    double Time[MAX][MAX][MAX];
    fill(Time[0][0],Time[0][0]+MAX*MAX*MAX,INF);   
    Time[s][1][N] = 0;
  
    while(!Q.empty()){
	State p = Q.top(); Q.pop();
	int v = p.F.S, vel = p.S.F;
	if(Time[v][vel][p.S.S] < p.F.F) continue;
 
	if(v == g && vel == 1){
	    return Time[g][1][p.S.S];
	}
  
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    for(int j = -1 ; j <= 1 ; j++){
		if(vel+j <= 0) continue;
		if(Time[v][vel][p.S.S] == 0 && j){
		    continue;
		}
		Edge e = G[v][i];
		if(e.to == p.S.S) continue;
		double t = (double)e.d/(vel+j);
		if(vel+j <= e.c && 
		   Time[v][vel][p.S.S] + t < Time[e.to][vel+j][v]){
		    Time[e.to][vel+j][v] = Time[v][vel][p.S.S] + t;
		    Q.push(State(pdi(Time[e.to][vel+j][v],e.to),pii(vel+j,v)));
		}
	    }
	}
    }
    return INF;
}
  
int main(){
    int x,y,d,c;
    while(cin >> N >> M, N){
	for(int i = 0 ; i < MAX ; i++){
	    G[i].clear();
	}
	cin >> s >> g; s--; g--;
	for(int i = 0 ; i < M ; i++){
	    cin >> x >> y >> d >> c;
	    x--; y--;
	    G[x].push_back(Edge(y,d,c));
	    G[y].push_back(Edge(x,d,c));
	}
	double res = dijkstra();
	if(res == INF){
	    cout << "unreachable" << endl;
	}else{
	    printf("%.8f\n",res);
	}
    }
    return 0;
}
