#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_V 100
#define MAX_E 10000
 
int V,E,par[MAX_V],rank[MAX_V];
 
struct Colony{
    double x,y,z,r;
    Colony(){}
    Colony(double x,double y,double z,double r) : x(x),y(y),z(z),r(r) {}
};
 
struct Edge{
    int u,v;
    double dist;
    Edge(){}
    Edge(int u,int v,double dist) : u(u),v(v),dist(dist) {}
};
 
bool comp(const Edge &e1,const Edge &e2){
    return e1.dist < e2.dist;
}
 
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
    x = find(x);
    y = find(y);
 
    if(x == y) return;
 
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
 
double kruskal(){
    sort(es,es+E,comp);
    init();
    double res = 0.0;
    for(int i = 0 ; i < E ; i++){
	Edge e = es[i];
	if(!same(e.u,e.v)){
	    unite(e.u,e.v);
	    res += e.dist;
	}
    }
    return res;
}
 
double getDist(const Colony &c1,const Colony &c2){
    return sqrt(pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2)+pow(c1.z-c2.z,2))-c1.r-c2.r;
}
 
int main(){
    while(cin >> V,V){
	E = 0;
	double x,y,z,r;
	Colony C[MAX_V];
	for(int i = 0 ; i < V ; i++){
	    cin >> x >> y >> z >> r;
	    C[i] = Colony(x,y,z,r);
	}
     
	for(int i = 0 ; i < V ; i++){
	    for(int j = i+1 ; j < V ; j++){
		double dist = getDist(C[i],C[j]);
		es[E++] = Edge(i,j,max(dist,0.0));
	    }
	}
	printf("%.3f\n",kruskal());
    }
    return 0;
}
