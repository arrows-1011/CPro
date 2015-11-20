#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 210
#define INF 1e9
const int diff = 105;
 
struct State{
    int n,x,y,t;
    bool operator < (const State &s)const{
	return n > s.n;
    }
};
 
int sx,sy,gx,gy,lx,ly;
bool can[MAX][MAX];
int dist[MAX][MAX][6];
const int dx[7] = {0,1,1,0,-1,-1,0};
const int dy[2][7] = {{1,0,-1,-1,-1,0,0},
                      {1,1,0,-1,0,1,0}};
 
inline bool inField(int x,int y){
    x -= diff; y -= diff;
    return -lx <= x && x <= lx && -ly <= y && y <= ly;
}
 
int dijkstra(){
    priority_queue<State> Q;
    Q.push((State){0,sx,sy,0});
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    for(int k = 0 ; k < 6 ; k++){
		dist[i][j][k] = INF;
	    }
	}
    }
    dist[sy][sx][0] = 0;
 
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int x = s.x, y = s.y, t = s.t;
	if(dist[y][x][t] < s.n) continue;
	if(x == gx && y == gy) return dist[gy][gx][t];
	int xx = x-diff,yy = y-diff;
	int ndir = abs(xx*yy*t)%6, nt = (t+1)%6;
	for(int i = 0 ; i < 7 ; i++){
	    int nx = x + dx[i], ny = y + dy[abs(xx)%2][i];
	    if(!inField(nx,ny) || !can[ny][nx]) continue;
	    if(i == ndir){
		if(dist[y][x][t] < dist[ny][nx][nt]){
		    dist[ny][nx][nt] = dist[y][x][t];
		    Q.push((State){dist[ny][nx][nt],nx,ny,nt});
		}
	    }else{
		if(dist[y][x][t]+1 < dist[ny][nx][nt]){
		    dist[ny][nx][nt] = dist[y][x][t]+1;
		    Q.push((State){dist[ny][nx][nt],nx,ny,nt});
		}
	    }
	}
    }
    return -1;
}
 
int main(){
    int N,x,y;
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    can[i][j] = true;
	}
    }
    cin >> sx >> sy >> gx >> gy >> N;
    sx += diff; sy += diff; gx += diff; gy += diff;
    for(int i = 0 ; i < N ; i++){
	cin >> x >> y;
	x += diff; y += diff;
	can[y][x] = false;
    }
    cin >> lx >> ly;
    cout << dijkstra() << endl;
    return 0;
}
