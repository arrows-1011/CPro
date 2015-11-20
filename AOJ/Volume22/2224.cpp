#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100000
 
int N, M;
int par[MAX], rank[MAX];
typedef pair<double,double> P;
void init(){
    for(int i = 0 ; i < N ; i++){
	par[i] = i;
	rank[i] = 0;
    }
}
 
int find(int x){
    if(par[x] == x){
	return x;
    }else{
	return par[x] = find(par[x]);
    }
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
 
struct edge{
    int u,v;
    double cost;
};
 
bool comp(const edge &e1,const edge &e2){
    return e1.cost > e2.cost;
}
 
edge es[MAX];
 
double kruskal(){
    init(); sort(es , es + M, comp);
    double res = 0;
    for(int i = 0 ; i < M ; i++){
	edge e = es[i];
	if(!same(e.u , e.v)){
	    unite(e.u , e.v);
	    res += e.cost;
	}
    }
    return res;
}
 
double dist(P p1, P p2){
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}
 
int main(){
    int a,b;
    P p[MAX];
 
    scanf("%d %d" ,&N ,&M);
    for(int i = 0 ; i < N ; i++){
	scanf("%lf%lf",&p[i].first, &p[i].second);
    }
    double total = 0;
    for(int i = 0 ; i < M ; i++){
	scanf("%d %d" ,&a ,&b);  
	a--, b--;
	double d = dist(p[a], p[b]);
	es[i].u = a; es[i].v = b; es[i].cost = d;
	total += d;
    }
    printf("%.5f\n",total-kruskal());
    return 0;
}
