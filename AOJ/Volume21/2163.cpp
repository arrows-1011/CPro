#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 20
#define MAX_W 20
 
int H,W;
int id[MAX_H][MAX_W];
 
bool check(int x,int y){
    const int dx[4] = {-1,0,-1,0};
    const int dy[4] = {-1,-1,0,0};
    if(x < 1 || y < 1) return true;
    set<int> st;
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i],ny = y + dy[i];
	st.insert(id[ny][nx]);
    }
    return (st.size() < 4);
}
 
int dfs(int x,int y,int num){
    if(x == W) return dfs(0,y+1,num);
    if(y == H) return 1;
    if(id[y][x] >= 0) return dfs(x+1,y,num);
    if(!check(x,y)) return 0;
 
    int res = 0;
    if(x+1 < W && id[y][x+1] == -1){
	id[y][x] = id[y][x+1] = num;
	res += dfs(x+2,y,num+1);
	id[y][x] = id[y][x+1] = -1;
    }
    if(y+1 < H && id[y+1][x] == -1){
	id[y][x] = id[y+1][x] = num;
	res += dfs(x+1,y,num+1);
	id[y][x] = id[y+1][x] = -1;
    }
    return res;
}
 
int main(){
    while(cin >> H >> W,H){
	memset(id,-1,sizeof(id));
	cout << dfs(0,0,0) << endl;
    }
    return 0;
}
