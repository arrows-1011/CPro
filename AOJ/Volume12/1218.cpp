#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 15
 
int H,W,px,py,bx,by,gx,gy;
int field[MAX][MAX];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
 
struct State{
    int x1,y1,x2,y2,d;
    State(int x1,int y1,int x2,int y2,int d) : 
	x1(x1),y1(y1),x2(x2),y2(y2),d(d) {}
};
 
bool Valid(int x,int y){
    if(field[y][x] == 1) return false;
    return 0 <= x && x < W && 0 <= y && y < H;
}
 
int bfs(){
    bool visited[MAX][MAX][MAX][MAX];
    memset(visited,false,sizeof(visited));
    deque<State> Q;
    Q.push_front(State(px,py,bx,by,0));
 
    while(!Q.empty()){
	State s = Q.front(); Q.pop_front();
	if(s.x2 == gx && s.y2 == gy){
	    return s.d;
	}
	if(visited[s.y1][s.x1][s.y2][s.x2]) continue;
	visited[s.y1][s.x1][s.y2][s.x2] = true;
     
	for(int i = 0 ; i < 4 ; i++){
	    int nx = s.x1 + dx[i];
	    int ny = s.y1 + dy[i];
	    if(nx == s.x2 && ny == s.y2) continue;
	    if(!Valid(nx,ny)) continue;
	    Q.push_front(State(nx,ny,s.x2,s.y2,s.d));
	}
	for(int i = 0 ; i < 4 ; i++){
	    int nx = s.x1 + dx[i];
	    int ny = s.y1 + dy[i];
	    int nnx = s.x2 + dx[i];
	    int nny = s.y2 + dy[i];
       
	    if(nx == s.x2 && ny == s.y2){
		if(Valid(nx,ny) && Valid(nnx,nny)){
		    Q.push_back(State(nx,ny,nnx,nny,s.d+1));
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
		if(field[i][j] == 4){
		    px = j; py = i;
		}else if(field[i][j] == 2){
		    bx = j; by = i;
		}else if(field[i][j] == 3){
		    gx = j; gy = i;
		}
	    }
	}
	cout << bfs() << endl;
    }
    return 0;
}
