#include <iostream>
#include <deque>
 
using namespace std;
 
#define MAX_H 100
#define MAX_W 100
#define MAX_A 10
 
struct State{
    int m,x,y,p,q,d;
    State(int m,int x,int y,int p,int q,int d) :
	m(m),x(x),y(y),p(p),q(q),d(d) {}
};
 
int H,W,A;
char field[MAX_H][MAX_W];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
bool visited[MAX_H][MAX_W][MAX_A][MAX_A][4];
 
inline bool canMove(int x,int y,int d){
    if(0 <= x && x < W && 0 <= y && y < H){
	if(field[y][x] == 'S' && d == 1){
	    return false;
	}else if(field[y][x] != '#'){
	    return true;
	}
    }
    return false;
}
 
int bfs(int sx,int sy,int gx,int gy){
    deque<State> Q;
    Q.push_back(State(0,sx,sy,A,A,3));
    visited[sy][sx][A][A][3] = true;
   
    while(!Q.empty()){
	State s = Q.front(); Q.pop_front();
	int x = s.x, y = s.y;
	if(x == gx && y == gy) return s.m;
	int nx = x+dx[s.d], ny = y+dy[s.d];
	if(canMove(nx,ny,s.d) && !visited[ny][nx][s.p][s.q][s.d]){
	    visited[ny][nx][s.p][s.q][s.d] = true;
	    Q.push_front(State(s.m,nx,ny,s.p,s.q,s.d));
	}
	if(s.p > 0 && field[y][x] == '.'){
	    int ndir = (s.d & 1 ? s.d+3 : s.d+1)%4;
	    if(!visited[y][x][s.p-1][s.q][ndir]){
		visited[y][x][s.p-1][s.q][ndir] = true;
		Q.push_back(State(s.m+1,x,y,s.p-1,s.q,ndir));
	    }
	}
	if(s.q > 0 && field[y][x] == '.'){
	    int ndir = (s.d & 1 ? s.d+1 : s.d+3)%4;
	    if(!visited[y][x][s.p][s.q-1][ndir]){
		visited[y][x][s.p][s.q-1][ndir] = true;
		Q.push_back(State(s.m+1,x,y,s.p,s.q-1,ndir));
	    }
	}
    }
    return -1;
}
 
int main(){
    int sx,sy,gx,gy;
    cin >> H >> W >> A;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	    if(field[i][j] == 'S'){
		sx = j; sy = i;
	    }else if(field[i][j] == 'G'){
		gx = j; gy = i;
	    }
	}
    }
    cout << bfs(sx,sy,gx,gy) << endl;
    return 0;
}
