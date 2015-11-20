#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 10
#define INF 1e9
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
 
int H,W,sx,sy,gx,gy;
int field[MAX][MAX];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
 
bool inField(int x,int y){
    return 0 <= x && x < W && 0 <= y && y < H;
}
 
int bfs(){
    queue<piii> Q;
    Q.push(piii(pii(sx,sy),6));
    int d[MAX][MAX][7];
    fill(d[0][0],d[0][0]+MAX*MAX*7,INF);
    d[sy][sx][6] = 0;
   
    while(!Q.empty()){
	piii p = Q.front(); Q.pop();
	int x = p.first.first, y = p.first.second;
	int life = p.second;
 
	if(x == gx && y == gy){
	    return d[y][x][life];
	}                                        
	if(life == 1) continue;
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    if(!inField(nx,ny)) continue;
	    if(field[ny][nx] == 0) continue;
	    if(field[ny][nx] == 4){
		if(d[y][x][life] + 1 < d[ny][nx][6]){
		    d[ny][nx][6] = d[y][x][life] + 1;
		    Q.push(piii(pii(nx,ny),6));
		}
	    }else{
		if(d[y][x][life] + 1 < d[ny][nx][life-1]){
		    d[ny][nx][life-1] = d[y][x][life] + 1;
		    Q.push(piii(pii(nx,ny),life-1));
		}
	    }
	}    
    }
    return -1;
}
 
int main(){
    while(cin >> W >> H, W){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == 2){
		    sx = j; sy = i;
		}else if(field[i][j] == 3){
		    gx = j; gy = i;
		}
	    }
	}
	cout << bfs() << endl;
    }
    return 0;
}
