#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1010
#define MAX_V 3010
#define INF 1e9
typedef pair<int,int> pii;
 
struct edge{
    int to,cap,cost,rev;
};
 
int V,h[MAX_V],dist[MAX_V];
int prevv[MAX_V],preve[MAX_V];
vector<edge> G[MAX_V];
 
void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
 
int min_cost_flow(int s,int t,int f){
    int res = 0;
    fill(h,h+V,0);
    while(f > 0){
	priority_queue<pii,vector<pii>,greater<pii> > Q;
	fill(dist,dist+V,INF);
	dist[s] = 0;
	Q.push(pii(0,s));
	while(!Q.empty()){
	    pii p = Q.top(); Q.pop();
	    int v = p.second;
	    if(dist[v] < p.first) continue;
	    for(int i = 0 ; i < (int)G[v].size() ; i++){
		edge &e = G[v][i];
		if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
		    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
		    prevv[e.to] = v; preve[e.to] = i;
		    Q.push(pii(dist[e.to],e.to));
		}
	    }
	}
	if(dist[t] == INF) return -1;
	for(int v = 0 ; v < V ; v++){
	    h[v] += dist[v];
	}
	int d = f;
	for(int v = t ; v != s ; v = prevv[v]){
	    d = min(d,G[prevv[v]][preve[v]].cap);
	}
	f -= d;
	res += d * h[t];
	for(int v = t ; v != s ; v = prevv[v]){
	    edge &e = G[prevv[v]][preve[v]];
	    e.cap -= d;
	    G[v][e.rev].cap += d;
	}
    }
    return res;
}
 
void init(){
    for(int i = 0 ; i < MAX_V ; i++){
	G[i].clear();
    }
}
 
int main(){
    set<int> st;
    int N,A[MAX_N],B[MAX_N];
    cin >> N; init();
    for(int i = 0 ; i < N ; i++){
	cin >> A[i] >> B[i];
	st.insert(A[i]); st.insert(B[i]);
    }
    int size = st.size();
    int s = N+size,t = s+1;
    V = N + size + 2;
    set<int>::iterator it;
    vector<int> vec;
    for(it = st.begin() ; it != st.end() ; ++it){
	vec.push_back(*it);
    }
    add_edge(s,t,size,0);
    for(int i = 0 ; i < N ; i++){
	int j = lower_bound(vec.begin(),vec.end(),A[i])-vec.begin();
	add_edge(j,size+i,1,-B[i]);
	j = lower_bound(vec.begin(),vec.end(),B[i])-vec.begin();
	add_edge(j,size+i,1,-A[i]);
    }
    for(int i = 0 ; i < size ; i++){
	add_edge(s,i,1,0);
    }
    for(int i = 0 ; i < N ; i++){
	add_edge(size+i,t,1,0);
    }
    cout << -min_cost_flow(s,t,size) << endl;
    return 0;
}
