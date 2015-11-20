#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 100000;
 
int par[MAX],rank[MAX],n,m;
 
void init(int n){
    for(int i = 0 ; i < n ; i++){
	par[i] = i;
	rank[i] = 0;
    }
}
 
int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}
 
void unite(int x,int y){
    x = find(x); y = find(y);
    if(x == y) return;
 
    if(rank[x] < rank[y]){
	par[x] = y;
    } else {
	par[y] = x;
	if(rank[x] == rank[y]) rank[x]++;
    }
}
 
bool same(int x,int y){
    return find(x) == find(y);
}
 
int kruskal(pair<int,pair<int,int> > es[MAX]){
    sort(es,es + m);
    init(n);
    int res = 0;
    for(int i = 0 ; i < m ; i++){
	int a = es[i].second.first;
	int b = es[i].second.second;
	if(!same(a,b)){
	    res += es[i].first;
	    unite(a,b);
	}
    }
    return res;
}
 
int main(){
    while(cin >> n,n){
	cin >> m;
	pair<int,pair<int,int> > es[MAX];
	for(int i = 0 ; i < m ; i++){
	    scanf("%d,%d,%d", &es[i].second.first, &es[i].second.second,&es[i].first);
	}
	for(int i = 0 ; i < m ; i++){
	    es[i].first = es[i].first/100-1;
	}
	cout << kruskal(es) << endl;
    }
    return 0;
}
