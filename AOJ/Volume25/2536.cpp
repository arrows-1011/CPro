#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;

#define MAX_N 1000
#define MAX_E 10000

int N,E;
int par[MAX_N+1],rank[MAX_N+1];
 
struct edge{
    int from,to,cost;
};
 
bool cmp(const edge& e1,const edge& e2){
    return e1.cost < e2.cost;
}
 
void init(int n){
    for(int i = 0 ; i < n ; i++){
	par[i] = i;
	rank[i] = 0;
    }
}
 
int find(int x){
    if (par[x] == x) {
	return x;
    } else {
	return par[x] = find(par[x]);
    }
}
 
void unite(int x,int y){
    x = find(x);
    y = find(y);
 
    if(x == y) return;
    if (rank[x] < rank[y]) {
	par[x] = y;
    } else {
	par[y] = x;
	if (rank[x] == rank[y]) {
	    rank[x]++;
	}
    }
}
 
bool same(int x,int y){
    return find(x) == find(y);
}
 
edge es[MAX_E+1];
 
void kruskal(vector<int> &v){
    sort(es ,es + E ,cmp);
    init(N);
 
    for(int i = 0 ; i < E ; i++){
	edge e = es[i];
	if (!same(e.from,e.to)) {
	    unite(e.from,e.to);
	    v.push_back(e.cost);
	}
    }
 
}
 
 
int main(){
    int a,b,c;
    while(cin >> N >> E , N | E){
	for(int i = 0 ; i < E ; i++){
	    cin >> a >> b >> c;
  
	    es[i].from = --a;
	    es[i].to = --b;
	    es[i].cost = c;
	}
 
	vector<int> v;
	kruskal(v);
 
	int size = (int)v.size();
	cout << v[size/2] << endl;
    }
 
    return 0;
}
