#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 101
#define MAX_E 10000
#define INF 1e9
 
int N, M, L;
struct edge{
    int to, dist, enemy;
    edge(int to, int dist, int enemy) : to(to), dist(dist), enemy(enemy) {}
};
 
struct State{
    int v, dist, l;
    State(int v, int dist, int l) : v(v), dist(dist), l(l) {}
 
    bool operator < (const State &s)const{
	return dist > s.dist;
    }
};
 
vector<edge> G[MAX_E];
int d[MAX_V][MAX_V];
 
int dijkstra(){
    int res = INF;
    priority_queue<State> Q;
    fill(d[0], d[N], INF);
    d[0][L] = 0;
    Q.push(State(0,0,L));
 
    while(!Q.empty()){
	State st = Q.top(); Q.pop();
	int v = st.v;
 
	if(v == N-1){
	    res = min(res, st.dist);
	    continue;
	}
 
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    edge e = G[v][i];
	    if(d[e.to][st.l] > d[v][st.l] + e.enemy){
		d[e.to][st.l] = d[v][st.l] + e.enemy;
		Q.push(State(e.to, d[e.to][st.l], st.l));
	    }
	}
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    edge e = G[v][i];
	    if(st.l - e.dist >= 0 && d[e.to][st.l-e.dist] > d[v][st.l]){
		d[e.to][st.l-e.dist] = d[v][st.l];
		Q.push(State(e.to, d[e.to][st.l-e.dist], st.l-e.dist));
	    }
	}
    }
    return res;
}
 
int main(){
    int a, b, d, e;
    while(cin >> N >> M >> L, (N | M | L)){
	for(int i = 0 ; i < MAX_E ; i++){
	    G[i].clear();
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> a >> b >> d >> e;
	    a--, b--;
	    G[a].push_back(edge(b,d,e));
	    G[b].push_back(edge(a,d,e));
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
