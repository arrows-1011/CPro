#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 510
#define MAX_E 50010
 
int par[MAX],rnk[MAX];
void init(int N){
    for(int i = 0 ; i < N ; i++){
	par[i] = i;
	rnk[i] = 0;
    }
}
 
int find(int x){
    if(par[x] == x){
	return x;
    }
    return par[x] = find(par[x]);
}
 
void unite(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(rnk[x] < rnk[y]){
	par[x] = y;
    }else{
	par[y] = x;
	if(rnk[x] == rnk[y]){
	    rnk[x]++;
	}
    }
}
 
bool same(int x,int y){
    return (find(x) == find(y));
}
 
struct Edge{ int u,v,cost; };
 
bool comp(const Edge &e1,const Edge &e2){
    return e1.cost < e2.cost;
}
 
int V,E;
Edge es[MAX_E];
 
bool equals(const Edge &e1,const Edge &e2){
    return (e1.u == e2.u && e1.v == e2.v);
}
 
vector<Edge> vec;
 
int kruskal(int ne){
    init(V);
    int res = 0;
    for(int i = 0 ; i < E ; i++){
	Edge e = es[i];
	if(ne != -1 && equals(e,vec[ne])){
	    continue;
	}
	if(!same(e.u,e.v)){
	    unite(e.u,e.v);
	    res += e.cost;
	}
    }
    return res;
}
 
int kruskal(){
    sort(es,es+E,comp);
    init(V);
    int res = 0;
    for(int i = 0 ; i < E ; i++){
	Edge e = es[i];
	if(!same(e.u,e.v)){
	    unite(e.u,e.v);
	    res += e.cost;
	    vec.push_back(e);
	}
    }
    return res;
}
 
int main(){
    int a,b,c;
    cin >> V >> E;
    for(int i = 0 ; i < E ; i++){
	cin >> a >> b >> c; a--; b--;
	es[i] = (Edge){a,b,c};
    }
    vec.clear();
    int cnt = 0, sum = 0;
    int res = kruskal();
    for(int i = 0 ; i < (int)vec.size() ; i++){
	int r = kruskal(i);
	bool check = true;
	for(int j = 0 ; j < V ; j++){
	    if(!same(0,j)){
		check = false;
		break;
	    }
	}
	if((check && r > res) || !check){
	    cnt++;
	    sum += vec[i].cost;
	}
    }
    cout << cnt << " " << sum << endl;
    return 0;
}
