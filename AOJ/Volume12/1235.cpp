#include <bits/stdc++.h>
  
using namespace std;
  
int N,C,cnt;
bool flg,visited[10][10];
vector<int> G[10];
int dx[6] = {-1,-1,0,0,1,1};
int dy[6] = {-1,0,-1,1,0,1};
  
bool inField(int x,int y){
    if(x > y || y >= N || x < 0 || y < 0){
	return false;
    }
    return true;
}
  
bool dfs(int x,int y,int c){
    if(G[y][x] == 0) return true;
    if(G[y][x] != c || visited[y][x]) return false;
    visited[y][x] = true; cnt++;
    bool res = false;
    for(int i = 0 ; i < 6 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(!inField(nx,ny)) continue;
	res |= dfs(nx,ny,c);
    }
    return res;
}
 
int solve(int x,int y){
    int res = 0;
    memset(visited,false,sizeof(visited));
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j <= i ; j++){
	    if(G[i][j] == 0) continue;
	    if(visited[i][j]) continue;
       
	    cnt = 0; flg = false;
	    if(dfs(j,i,G[i][j])) continue;
	    res += (G[i][j] != C ? cnt : -cnt);
	}
    }
    return res;
}
  
int main(){
    int in;
    while(cin >> N >> C,(N|C)){
	for(int i = 0 ; i < N ; i++){
	    G[i].clear();
	    for(int j = 0 ; j <= i ; j++){
		cin >> in;
		G[i].push_back(in);
	    }
	}
	int res = INT_MIN;
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j <= i ; j++){
		if(G[i][j] == 0){
		    G[i][j] = C;
		    res = max(res,solve(j,i));
		    G[i][j] = 0;
		}
	    }
	}
	cout << res << endl;
    }
    return 0;
}
