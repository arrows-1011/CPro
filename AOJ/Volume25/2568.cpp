#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100001
#define MOD 1000000007
typedef long long ll;
 
int par[MAX],rank[MAX];
 
void init(int N){
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
    return (find(x) == find(y));
}
 
ll mod_pow(ll x,ll n){
    if(n == 0) return 1;
    ll res = mod_pow(x*x%MOD,n/2);
    if(n & 1) res = res*x%MOD;
    return res;
}
 
int main(){
    int N,M,a,b;
    while(cin >> N >> M,N){
	init(N);
	for(int i = 0 ; i < M ; i++){
	    cin >> a >> b; a--; b--;
	    unite(a,b);
	}
	ll cnt = 0;
	bool visited[MAX] = {false};
	for(int i = 0 ; i < N ; i++){
	    int x = find(i);
	    if(!visited[x]){
		visited[x] = true;
		cnt++;
	    }
	}
	ll res = mod_pow(2,cnt);
	if(cnt != N) ++res;
	cout << res%MOD << endl;
    }
    return 0;
}
