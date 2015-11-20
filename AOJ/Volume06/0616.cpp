#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100010
#define INF LLONG_MAX/4
typedef long long ll;
 
struct State{
    ll v,cost;
 
    State(ll v,ll cost) :
	v(v),cost(cost) {}
 
    bool operator > (const State &s)const{
	return cost > s.cost;
    }
};
 
struct P{
    ll idx,cost;
    P(ll idx,ll cost) :
	idx(idx),cost(cost) {}
    bool operator < (const P &p)const{
	return cost < p.cost;
    }
};
 
struct Edge{
    ll to,cost;
 
    Edge(ll to,ll cost) :
	to(to),cost(cost) {}
};
 
ll N,M,d[MAX];
vector<Edge> G[MAX];
 
void dijkstra(){
    fill(d,d+N,INF);
    d[0] = 0;
    priority_queue<State,vector<State>,greater<State> > Q;
    Q.push(State(0,0));
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	ll v = s.v;
	if(d[v] < s.cost) continue;
	for(int i = 0 ; i < (int)G[v].size() ; i++){
	    Edge e = G[v][i];
	    if(d[v] + e.cost < d[e.to]){
		d[e.to] = d[v] + e.cost;
		Q.push(State(e.to,d[e.to]));
	    }
	}
    }
}
 
int main(){
    ll C,a,b,c,sum = 0;
    cin >> N >> M >> C;
    for(int i = 0 ; i < M ; i++){
	cin >> a >> b >> c;
	a--; b--;
	G[a].push_back(Edge(b,c));
	G[b].push_back(Edge(a,c));
	sum += c;
    }
    dijkstra();
    vector<P> v;
    for(int i = 0 ; i < N ; i++){
	v.push_back(P(i,d[i]));
    }
    sort(v.begin(),v.end());
    ll res = INF,dist = 0;
    set<ll> st;
    for(int i = 0 ; i < N ; i++){
	ll idx = v[i].idx;
	for(int j = 0 ; j < (int)G[idx].size() ; j++){
	    if(st.find(G[idx][j].to) != st.end()){
		dist += G[idx][j].cost;
	    }
	}
	st.insert(idx);
	res = min(res,sum-dist+v[i].cost*C);
    }
    cout << res << endl;
    return 0;
}
