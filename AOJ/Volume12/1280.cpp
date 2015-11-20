#include <iostream>
#include <algorithm>
#include <set>
  
using namespace std;
  
#define MAX_V 100
#define MAX_E 10000
#define INF 1e9
typedef pair<int,int> pii;
  
struct Edge{
    int u,v,cost;
    Edge(){}
    Edge(int u,int v,int cost) : u(u),v(v),cost(cost) {}
};
  
bool cmp(const Edge &e1,const Edge &e2){
    return e1.cost < e2.cost;
}
  
int V,E,par[MAX_V],rank[MAX_V],wmin;
Edge es[MAX_E];
  
void init(){
    for(int i = 0 ; i < V ; i++){
	par[i] = i;
	rank[i] = 0;
    }
}
  
int find(int x){
    if(par[x] == x){
	return x;
    }
    return par[x] = find(par[x]);
}
  
void unite(int x,int y){
    x = find(x), y = find(y);
    if(x == y){
	return;
    }
    if(rank[x] < rank[y]){
	par[x] = y;
    }else{
	par[y] = x;
	if(rank[x] == rank[y]){
	    rank[x]++;
	}
    }
}
  
bool same(int x,int y){
    return find(x) == find(y);
}
  
int kruskal(){
    init();
    sort(es,es+E,cmp);
    set<pii> v;
    int max = 0, min = INF;
    for(int i = 0 ; i < E ; i++){
	Edge e = es[i];
	if(!same(e.u,e.v) && wmin <= e.cost){
	    unite(e.u,e.v);
	    v.insert(pii(e.u,e.v));
	    max = std::max(max,e.cost);
	    min = std::min(min,e.cost);
	} 
    }
    if((int)v.size() != V-1){
	return INF;
    }
    return max-min;
}
  
int main(){
    while(cin >> V >> E, (V | E)){
	int a,b,c;
	set<int> w;
	for(int i = 0 ; i < E ; i++){
	    cin >> a >> b >> c;
	    a--, b--;
	    es[i] = Edge(a,b,c);
	    w.insert(c);
	}
	int res = 1e9;
	set<int>::iterator it;
	for(it = w.begin() ; it != w.end() ; ++it){
	    wmin = *it;
	    res = min(res,kruskal());
	}
	cout << (res == INF ? -1 : res) << endl;
    }
    return 0;
}
