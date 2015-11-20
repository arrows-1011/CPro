#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX_H 60
#define MAX_W 60
#define INF 1e9
  
int H,W,N,ix,iy,ox,oy;
bool wall[MAX_H][MAX_W][4],a[MAX_H][MAX_W][4];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
  
struct P{
    int x,y;
    P(int x,int y) : x(x),y(y) {}
};
  
inline bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}
  
int bfs(){
    int d[MAX_H][MAX_W];
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    d[i][j] = INF;
	}
    }
    d[iy][ix] = 0;
    queue<P> Q;
    Q.push(P(ix,iy));
    queue<int> step;
    step.push(0);
  
    while(!Q.empty()){
	P p = Q.front(); Q.pop();
	int s = step.front(); step.pop();
	int x = p.x, y = p.y;
	if(x == ox && y == oy) return d[oy][ox];
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i], ny = y + dy[i];
	    if(wall[y][x][i]) continue;
	    if(!inField(nx,ny)) continue;
	    if(d[y][x]+1 < d[ny][nx]){
		d[ny][nx] = d[y][x]+1;
		Q.push(P(nx,ny));
		step.push(s+1);
	    }
	}
    }
    return -1;
}
  
int main(){
    cin >> W >> H >> N;
    for(int i = 0 ; i < N ; i++){
	int sx,sy,dx,dy;
	cin >> sx >> sy >> dx >> dy;
	if(sx > dx) swap(sx,dx);
	if(sy > dy) swap(sy,dy);
	bool t = false,y = false;
	if(sx != dx) y = true;
	if(sy != dy) t = true;
	if(y){
	    for(int j = sx ; j < dx ; j++){
		for(int k = sy ; k <= dy ; k++){
		    if(k-1 >= 0){
			wall[k-1][j][3] = true;
			a[k-1][j][3] = true;
		    }
		    wall[k][j][1] = true;
		    a[k][j][1] = true;
		}
	    }
	}
	if(t){
	    for(int j = sx ; j <= dx ; j++){
		for(int k = sy ; k < dy ; k++){
		    if(j-1 >= 0){
			wall[k][j-1][2] = true;
			a[k][j-1][2] = true;
		    }
		    wall[k][j][0] = true;
		    a[k][j][0] = true;
		}
	    }
	}
    }
    int res = 0;
    cin >> ix >> iy >> ox >> oy;
    int dist = bfs();
    for(int x = 0 ; x <= W+1 ; x++){
	for(int y = 0 ; y <= H+1 ; y++){
	    int xx = x-1,yy = y;
	    if(xx >= 0) wall[yy][xx][2] = wall[y][x][0] = true;
	    res = max(res,bfs()-dist);
	    if(xx >= 0){
		wall[yy][xx][2] = a[yy][xx][2];
		wall[y][x][0] = a[y][x][0];
	    }
	}
    }
    for(int x = 0 ; x <= W+1 ; x++){
	for(int y = 0 ; y <= H+1 ; y++){
	    int xx = x,yy = y-1;
	    if(yy >= 0) wall[yy][xx][3] = wall[y][x][1] = true;
	    res = max(res,bfs()-dist);
	    if(yy >= 0){
		wall[yy][xx][3] = a[yy][xx][3];
		wall[y][x][1] = a[y][x][1];
	    }
	}
    }
    cout << res << endl;
    return 0;
}
