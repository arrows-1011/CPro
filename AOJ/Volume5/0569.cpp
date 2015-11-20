#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
 
int H,W;
int bdg[MAX][MAX];
bool visited[MAX][MAX];
int dx[2][6] = {{-1,0,-1,1,-1,0},{0,1,-1,1,0,1}};
int dy[6] = {-1,-1,0,0,1,1};
 
bool inField(int x,int y){
    return 0 <= x && x <= W+1 && 0 <= y && y <= H+1;
}
 
int solve(int x,int y){
    visited[y][x] = true;
 
    int res = 0;
    for(int i = 0 ; i < 6 ; i++){
	int nx = x + dx[y%2][i];
	int ny = y + dy[i];
	if(!inField(nx,ny)) continue;
	if(bdg[ny][nx] == 1){
	    res++;
	}else if(!visited[ny][nx]){
	    res += solve(nx,ny);
	}
    }
    return res;
}
 
int main(){
    cin >> W >> H;
    memset(bdg,0,sizeof(bdg));
    for(int i = 1 ; i <= H ; i++){
	for(int j = 1 ; j <= W ; j++){
	    cin >> bdg[i][j];
	}
    }
    memset(visited,false,sizeof(visited));
    cout << solve(0,0) << endl;
    return 0;
}
