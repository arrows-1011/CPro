#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1100000
#define MAX_N 1010
#define MAX_H 1010
#define MAX_W 1010
 
int par[MAX],rank[MAX];
 
void init(){
    for(int i = 0 ; i < MAX ; i++){
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
 
int H,W,N,start,goal;
int x[MAX_N],y[MAX_N];
char field[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
 
int solve(){
    init();
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    if(field[i][j] == '#') continue;
	    for(int k = 0 ; k < 4 ; k++){
		int nx = j + dx[k];
		int ny = i + dy[k];
		if(0 > nx || W <= nx || 0 > ny || H <= ny){
		    continue;
		}
		if(field[ny][nx] == '#') continue;
		if(!same(i*W+j,ny*W+nx)){
		    unite(i*W+j,ny*W+nx);
		}
	    }
	}
    }
    if(same(start,goal)){
	return 0;
    }
    for(int i = 0 ; i < N ; i++){
	field[y[i]][x[i]] = '.';
	for(int j = 0 ; j < 4 ; j++){
	    int nx = x[i] + dx[j];
	    int ny = y[i] + dy[j];
	    if(0 > nx || W <= nx || 0 > ny || H <= ny){
		continue;
	    }
	    if(field[ny][nx] == '#') continue;
	    if(!same(y[i]*W+x[i],ny*W+nx)){
		unite(y[i]*W+x[i],ny*W+nx);
	    }
	}
	if(same(start,goal)){
	    return i+1;
	}
    }
    return -1;
}
 
int main(){
    while(cin >> W >> H){
	start = 0;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == 't'){
		    field[i][j] = '.';
		    goal = i*W+j;
		}
	    }
	}
	cin >> N;
	for(int i = 0 ; i < N ; i++){
	    cin >> x[i] >> y[i];
	}
	cout << solve() << endl;
    }
    return 0;
}
