#include <iostream>
#include <algorithm>
 
using namespace std;

#define MAX 20
#define INF 1e9
 
int H,W,sx,sy,ans;
int field[MAX][MAX];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};
 
bool cur(int &x,int &y,int dir,int &g){
    while(true){
	if(0 > x || x >= H || 0 > y || y >= W){
	    return false;
	}
	if(field[x][y] == 1){
	    field[x][y] = 0;
	    x -= dx[dir];
	    y -= dy[dir];
	    return true;
	}
	if(field[x][y] == 3){
	    g = 1;
	    return true;
	}
 
	x += dx[dir];
	y += dy[dir];
    }
}
 
void solve(int x,int y,int cnt){
    if(field[x][y] == 3){
	ans = min(ans,cnt);
	return;
    }
 
    if(cnt == 11){
	return;
    }
 
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
 
	if(0 > nx || nx >= H || 0 > ny || ny >= W || field[nx][ny] == 1){
	    continue;
	}
 
	int xx = x, yy = y,g = -1;
	if(cur(xx,yy,i,g)){
	    if(g == 1){
		ans = min(ans,cnt);
		return;
	    }
	    solve(xx,yy,cnt+1);
	    xx += dx[i];
	    yy += dy[i];
	    field[xx][yy] = 1;
	}
    }
  
}
 
int main(){
    while(cin >> W >> H, W | H){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
     
		if(field[i][j] == 2){
		    sx = i;
		    sy = j;
		    field[i][j] = 0;
		}
 
	    }
	}
 
	ans = INF;
	solve(sx,sy,1);
 
	if(ans == INF){
	    cout << -1 << endl;
	}else{
	    cout << ans << endl;
	}
    }
    return 0;
}
