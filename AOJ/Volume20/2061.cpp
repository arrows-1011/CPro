#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 30
#define MAX_M 20
#define INF (1<<29)
 
int N,M,mini,ansS;
bool edge[MAX_M][MAX_N];
 
class Union_Find{
public:
    int par[MAX_M],rank[MAX_M],size[MAX_M];
    Union_Find(int N){
	for(int i = 0 ; i < N ; i++){
	    par[i] = i;
	    rank[i] = 0;
	    size[i] = 1;
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
    }
 
    bool same(int x,int y){
	return find(x) == find(y);
    }
 
    int getSize(int x){
	return size[find(x)];
    }
};
 
bool check(int S){
    int idx = 0,arr[MAX_M];
    if(S == 0) return false;
    for(int i = 0 ; i < N ; i++){
	if(S >> i & 1){
	    arr[idx++] = i;
	}
    }
    Union_Find uf(M);
    for(int i = 0 ; i < M ; i++){
	for(int j = i+1 ; j < M ; j++){
	    if(uf.same(i,j)) continue;
	    for(int k = 0 ; k < idx ; k++){
		if(edge[i][arr[k]] && edge[j][arr[k]]){
		    uf.unite(i,j);
		}
	    }
	}
    }
    return (uf.getSize(0) == M);
}
 
void rec(int idx,int S,int num){
    if(num < mini && check(S)){
	mini = num; ansS = S;
	return;
    }
    if(num == 5 || num >= mini) return;
    for(int i = idx ; i < N ; i++){
	if(S >> i & 1) continue;
	rec(i+1,S|(1<<i),num+1);
    }
}
 
int main(){
    int K;
    bool blank = false;
    string lang[MAX_N],in;
    while(cin >> N >> M, N){
	map<string,int> mp;
	memset(edge,false,sizeof(edge));
	if(blank){ cout << endl; }
	blank = true;
	for(int i = 0 ; i < N ; i++){
	    cin >> lang[i];
	    mp[lang[i]] = i;
	}
	for(int i = 0 ; i < M ; i++){
	    cin >> K;
	    for(int j = 0 ; j < K ; j++){
		cin >> in;
		edge[i][mp[in]] = true;
	    }
	}
	mini = INF;
	rec(0,0,0);
	if(mini == INF){
	    cout << "Impossible" << endl;
	}else{
	    cout << __builtin_popcount(ansS) << endl;
	    for(int i = 0 ; i < N ; i++){
		if(ansS >> i & 1){
		    cout << lang[i] << endl;
		}
	    }
	}
    }
    return 0;
}
