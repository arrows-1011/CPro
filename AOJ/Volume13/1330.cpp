#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100010
typedef pair<int,int> pii;
 
class Union_Find{
public:
    int par[MAX],rank[MAX],W[MAX];
    Union_Find(int N){
	for(int i = 0 ; i < N ; i++){
	    par[i] = i;
	    rank[i] = W[i] = 0;
	}
    }
 
    pii find(int x){
	if(par[x] == x) return pii(x,0);
	pii p = find(par[x]);
	par[x] = p.first;
	W[x] = (p.second += W[x]);
	return p;
    }
 
    void unite(int x,int y,int w){
	pii nx = find(x), ny = find(y);
	x = nx.first; y = ny.first;
	if(x == y) return;
	w -= nx.second-ny.second;
	if(rank[x] < rank[y]){
	    par[x] = y; W[x] = w;
	}else{
	    par[y] = x; W[y] = -w;
	    if(rank[x] == rank[y]){
		rank[x]++;
	    }
	}
    }
 
    bool same(int x,int y){
	return (find(x).first == find(y).first);
    }
 
    int diff(int a,int b){
	return W[a]-W[b];
    }
};
 
int main(){
    int N,M,a,b,c;
    while(cin >> N >> M,N){
	Union_Find uf(N);
	for(int i = 0 ; i < M ; i++){
	    char ch;
	    cin >> ch >> a >> b;
	    a--; b--;
	    if(ch == '!'){
		cin >> c;
		uf.unite(a,b,c);
	    }else{
		if(uf.same(a,b)){
		    cout << uf.diff(a,b) << endl;
		}else{
		    puts("UNKNOWN");
		}
	    }
	}
    }
    return 0;
}
