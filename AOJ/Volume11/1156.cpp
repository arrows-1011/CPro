#include <iostream>
#include <queue>
 
using namespace std;
 
#define MAX_H 30
#define MAX_W 30
#define INF (1<<29)
 
struct State{
    int cost,x,y,dir;
    State(int cost,int x,int y,int dir) :
	cost(cost),x(x),y(y),dir(dir) {}
 
    bool operator < (const State &s)const{
	return cost > s.cost;
    }
};
 
int H,W,c[4];
int s[MAX_H][MAX_W];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
 
bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}
 
int dijkstra(){
    int d[MAX_H][MAX_W][4];
    fill(d[0][0],d[0][0]+MAX_H*MAX_W*4,INF);
    d[0][0][2] = 0;
    priority_queue<State> Q;
    Q.push(State(0,0,0,2));
    while(!Q.empty()){
	State cur = Q.top(); Q.pop();
	int x = cur.x,y = cur.y,dir = cur.dir;
	if(d[y][x][dir] < cur.cost) continue;
	if(x == W-1 && y == H-1) return d[y][x][dir];
	for(int i = 0 ; i < 4 ; i++){
	    int ndir = (dir+i)%4;
	    int nx = x + dx[ndir];
	    int ny = y + dy[ndir];
	    if(!inField(nx,ny)) continue;
	    if(s[y][x] == i){
		if(d[y][x][dir] < d[ny][nx][ndir]){
		    d[ny][nx][ndir] = d[y][x][dir];
		    Q.push(State(d[ny][nx][ndir],nx,ny,ndir));
		}
	    }else{
		if(d[y][x][dir] + c[i] < d[ny][nx][ndir]){
		    d[ny][nx][ndir] = d[y][x][dir] + c[i];
		    Q.push(State(d[ny][nx][ndir],nx,ny,ndir));
		}
	    }
	}
    }
    return -1;
}
 
int main(){
    while(true){
	cin >> W >> H;
	if(W == 0 && H == 0) break;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> s[i][j];
	    }
	}
	for(int i = 0 ; i < 4 ; i++){
	    cin >> c[i];
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
