#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 50010
 
class Union_Find{
public:
    int par[MAX],rank[MAX],size[MAX],gnum;
    Union_Find(int N){
	gnum = N;
	for(int i = 0 ; i < MAX ; i++){
	    par[i] = i;
	    rank[i] = 0;
	    size[i] = 0;
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
	    size[y] += size[x];
	}else{
	    par[y] = x;
	    size[x] += size[y];
	    if(rank[x] == rank[y]){
		rank[x]++;
	    }
	}
	gnum--;
    }
    bool same(int x,int y){
	return find(x) == find(y);
    }
    int getSize(int x){
	return size[find(x)];
    }
    int groups(){
	return gnum;
    }
};
 
int N,W,H;
int X[2*MAX],Y[2*MAX],x[MAX],y[MAX];
 
bool isWall(int x,int y){
    if(x == 1 || y == 1 || x == W || y == H){
	return true;
    }
    return false;
}
 
int main(){
    cin >> N >> W >> H;
    Union_Find uf(N);
    for(int i = 0 ; i < 2*MAX ; i++){
	X[i] = Y[i] = -1;
    }
    bool wall = false;
    for(int i = 0 ; i < N ; i++){
	cin >> x[i] >> y[i];
	uf.size[i] = 1;
	if(X[x[i]] == -1){
	    X[x[i]] = i;
	}else{
	    uf.unite(X[x[i]],i);
	}
	if(Y[y[i]] == -1){
	    Y[y[i]] = i;
	}else{
	    uf.unite(Y[y[i]],i);
	}
	wall |= isWall(x[i],y[i]);
    }
    if(uf.groups() == 1){
	cout << uf.getSize(0)-1 << endl;
    }else{
	int sum = 0;
	set<int> visited;
	for(int i = 0 ; i < N ; i++){
	    int f = uf.find(i);
	    if(!visited.count(f)){
		visited.insert(f);
		sum += uf.getSize(i)-1;
	    }
	}
	cout << sum+(uf.groups()-1)*2+1-wall << endl;
    }
    return 0;
}
