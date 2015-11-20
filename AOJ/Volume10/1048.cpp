#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 10
#define INF 1e9
typedef pair<int,int> pii;
typedef pair<string,int> psi;
 
struct Edge{
    int to,dist;
    Edge(int t,int d) : to(t),dist(d) {}
};
 
struct State{
    int cost,dist,v,S;
    State(int c,int d,int v,int S) 
	: cost(c),dist(d),v(v),S(S) {}
    bool operator < (const State &s)const{
	if(cost != s.cost){
	    return cost > s.cost;
	}else{
	    return dist > s.dist;
	}
    }
};
 
int V,E,K[MAX_N],q;
string shopping_list[15];
vector<psi> items[MAX_N];
vector<Edge> G[MAX_N+1];
 
void solve(){
    priority_queue<State> Q;
    Q.push(State(0,0,0,0));
    pii d[MAX_N+1][1<<15];
    for(int i = 0 ; i <= V ; i++){
	for(int j = 0 ; j < (1<<q) ; j++){
	    d[i][j] = pii(INF,INF);
	}
    }
    d[0][0] = pii(0,0);
   
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int v = s.v,S = s.S;
	if(d[v][S] < pii(s.cost,s.dist)) continue;
	if(v == 0 && S == (1<<q)-1){
	    cout << s.cost << " " << s.dist << endl;
	    return;
	}   
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    pii next = pii(d[v][S].first,d[v][S].second+e.dist);
	    if(next < d[e.to][S]){
		d[e.to][S] = next;
		Q.push(State(d[e.to][S].first,d[e.to][S].second,e.to,S));
	    }
	    if(v == 0) continue;
	    for(int j = 0 ; j < q ; j++){
		if((S >> j) & 1) continue;
		for(int k = 0 ; k < K[v-1] ; k++){
		    if(shopping_list[j] == items[v-1][k].first){
			pii next = pii(s.cost + items[v-1][k].second,
				       s.dist + e.dist);
			int nS = S|(1<<j);
			if(next < d[e.to][nS]){
			    d[e.to][nS] = next;
			    Q.push(State(d[e.to][nS].first,d[e.to][nS].second,e.to,nS));
			}
			next.second -= e.dist;
			if(next < d[v][nS]){
			    d[v][nS] = next;
			    Q.push(State(d[v][nS].first,d[v][nS].second,v,nS));
			}
		    }
		}
	    }
	}
    }
    cout << "impossible" << endl;
}
 
int main(){
    while(cin >> V, V){
	string name;
	int value,a,b,d;
	for(int i = 0 ; i <= V ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < V ; i++){
	    cin >> K[i];
	    items[i].clear();
	    for(int j = 0 ; j < K[i] ; j++){
		cin >> name >> value;
		items[i].push_back(psi(name,value));
	    }
	}
	cin >> q;
	for(int i = 0 ; i < q ; i++){
	    cin >> shopping_list[i];
	}
	cin >> E;
	for(int i = 0 ; i < E ; i++){
	    cin >> a >> b >> d;
	    G[a].push_back(Edge(b,d));
	    G[b].push_back(Edge(a,d));
	}
	solve();
    }
    return 0;
}
