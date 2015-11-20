#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 5432
 
class Union_Find{
public:
    int par[MAX],rank[MAX];
    Union_Find(int N){
	for(int i = 0 ; i < N ; i++){
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
};
 
int main(){
    int N,M,x[MAX];
    string a[MAX],s,t;
    map<string,int> mp;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> a[i] >> x[i];
	mp[a[i]] = i;
    }
    Union_Find uf(N);
    cin >> M;
    while(M--){
	cin >> s >> t;
	uf.unite(mp[s],mp[t]);
    }
    int res = 0;
    for(int i = 0 ; i < N ; i++){
	int min = (1<<29);
	for(int j = 0 ; j < N ; j++){
	    if(uf.same(i,j)){
		min = std::min(min,x[j]);
	    }
	}
	res += min;
    }
    cout << res << endl;
    return 0;
}
