#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 1001
#define MAX_N 100
#define MAX_M 100
 
struct P{
    int u,v;
    double cost;
    P(int u,int v,double cost) :
	u(u),v(v),cost(cost) {}
 
    bool operator < (const P &p)const{
	return cost < p.cost;
    }
};
 
int V,match[MAX_V],M;
vector<int> G[MAX_V];
vector<P> vec;
bool used[MAX_V];
 
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
 
bool dfs(int v){
    used[v] = true;
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	int u = G[v][i],w = match[u];
	if(w < 0 || (!used[w] && dfs(w))){
	    match[v] = u;
	    match[u] = v;
	    return true;
	}
    }
    return false;
}
 
int bipartite_matching(){
    int res = 0;
    memset(match,-1,sizeof(match));
    for(int v = 0 ; v < V ; v++){
	if(match[v] < 0){
	    memset(used,false,sizeof(used));
	    if(dfs(v)){ res++; }
	}
    }
    return res;
}
 
double getDist(double x1,double y1,double x2,double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
 
bool c(int x){
    for(int i = 0 ; i < MAX_V ; i++){ G[i].clear(); }
    for(int i = 0 ; i < x ; i++){
	add_edge(vec[i].u,vec[i].v);
    }
    return (bipartite_matching() == M);
}
 
void solve(){
    int l = 0, r = vec.size();
    while(r - l > 0){
	int mid = (l + r) / 2;
	if(c(mid)){
	    r = mid;
	}else{
	    l = mid+1;
	}
    }
    printf("%.10f\n",vec[r-1].cost);
}
 
int main(){
    int N;
    double x[MAX_N],y[MAX_N],v[MAX_N];
    while(cin >> N >> M, N){
	for(int i = 0 ; i < N ; i++){
	    cin >> x[i] >> y[i] >> v[i];
	}
	vec.clear();
	for(int i = 0 ; i < M ; i++){
	    int X,Y;
	    cin >> X >> Y;
	    for(int j = 0 ; j < N ; j++){
		vec.push_back(P(j,i+N,getDist(x[j],y[j],X,Y)/v[j]));
	    }
	}
	V = N + M;
	sort(vec.begin(),vec.end());
	solve();
    }
    return 0;
}
