#include <iostream>

using namespace std;

const int MAX = 51;
 
int island[MAX][MAX],H,W;
int dx[8]={1,1,1,-1,-1,-1,0,0},dy[8]={0,1,-1,0,1,-1,-1,1};
 
 
void dfs(int x,int y){
    island[x][y] = 0;
 
    for(int i = 0 ; i < 8 ; i++){
	int nx = dx[i] + x;
	int ny = dy[i] + y;
	if(0 <= nx && nx < W && 0 <= ny && ny < H)
	    if(island[nx][ny]) dfs(nx,ny);
    }
}
 
int main(){
    while(cin >> H >> W ,H + W){
	for(int i = 0 ; i < W ; i++)
	    for(int j = 0 ; j < H ; j++)
		cin >> island[i][j];
     
	int ans = 0;
	for(int i = 0 ; i < W ; i++){
	    for(int j = 0 ; j < H ; j++){
		if(island[i][j]){
		    dfs(i,j);
		    ans++;
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
