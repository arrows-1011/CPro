#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 50
#define MAX_W 50
#define MAX_S 10
 
struct State{
    int d,x,y,s,f;
    State(int d,int x,int y,int s,int f) :
	d(d),x(x),y(y),s(s),f(f) {}
};
 
char M[MAX_H][MAX_W];
bool visited[MAX_H][MAX_W][1<<MAX_S][2];
 
int getFloor(int x,int y,int f){
    if(M[y][x] == '|') return f;
    if(M[y][x] == '_' || islower(M[y][x])){
	return 0;
    }
    return 1;
}
 
int main(){
    int H,W,sx,sy,gx,gy,S;
    char MS[MAX_H][MAX_W][MAX_S];
    cin >> W >> H;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> M[i][j];
	    if(M[i][j] == '%'){
		M[i][j] = '_';
		sx = j; sy = i;
	    }
	    if(M[i][j] == '&'){
		M[i][j] = '_';
		gx = j; gy = i;
	    }
	}
    }
    cin >> S;
    for(int i = 0 ; i < S ; i++){
	for(int j = 0 ; j < H ; j++){
	    for(int k = 0 ; k < W ; k++){
		cin >> MS[j][k][i];
	    }
	}
    }
    int ans = -1;
    memset(visited,false,sizeof(visited));
    visited[sy][sx][0][0] = true;
    const int dx[] = {-1,0,1,0};
    const int dy[] = {0,-1,0,1};
    queue<State> Q;
    Q.push(State(0,sx,sy,0,0));
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int x = s.x, y = s.y;
	if(x == gx && y == gy){
	    ans = s.d;
	    break;
	}
	if(islower(M[y][x])){
	    int sw = M[y][x] - 'a';
	    int next = s.s ^ (1<<sw);
	    int nf = s.f;
	    if(MS[y][x][sw] == '*'){
		nf = 1-nf;
	    }
	    if(!visited[y][x][next][nf]){
		visited[y][x][next][nf] = true;
		Q.push(State(s.d+1,x,y,next,nf));
	    }
	}
	if(isupper(M[y][x])){
	    int sw = M[y][x] - 'A';
	    int next = s.s ^ (1<<sw);
	    int nf = s.f;
	    if(MS[y][x][sw] == '*'){
		nf = 1-nf;
	    }
	    if(!visited[y][x][next][nf]){
		visited[y][x][next][nf] = true;
		Q.push(State(s.d+1,x,y,next,nf));
	    }
	}
	if(M[y][x] == '|'){
	    int next = 1-s.f;
	    if(!visited[y][x][s.s][next]){
		visited[y][x][s.s][next] = true;
		Q.push(State(s.d+1,x,y,s.s,next));
	    }
	}
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    int f = s.f;
	    if(0 > nx || W <= nx || 0 > ny || H <= ny){
		continue;
	    }
	    if(M[ny][nx] == '#') continue;
	    int nf = getFloor(nx,ny,f);
	    for(int j = 0 ; j < S ; j++){
		if((s.s >> j) & 1){
		    if(MS[ny][nx][j] == '*'){
			nf = 1 - nf;
		    }
		}
	    }
	    if(f == nf && !visited[ny][nx][s.s][nf]){
		visited[ny][nx][s.s][nf] = true;
		Q.push(State(s.d+1,nx,ny,s.s,nf));
	    }
	}
    }
    cout << ans << endl;
    return 0;
}
