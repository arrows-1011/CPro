#include <bits/stdc++.h>
 
using namespace std;
 
#define H 19
#define W 15
 
struct State{
    int x,y,S;
    State(int x,int y,int S) : x(x),y(y),S(S) {}
   
    bool operator < (const State &s)const{
	if(x != s.x){
	    return x < s.x;
	}else if(y != s.y){
	    return y < s.y;
	}else{
	    return S < s.S;
	}
    }
};
 
int num[H][W];
char field[H][W];
map<State,int> step;
const int dx[8] = {-1,-1,-1,0,0,1,1,1};
const int dy[8] = {-1,0,1,-1,1,-1,0,1};
 
inline bool inH(int y){
    return (0 <= y && y < H);
}
 
inline bool inW(int x){
    return (0 <= x && x < W);
}
 
inline bool inField(int x,int y){
    return (inH(y) && inW(x));
}
 
int bfs(int sx,int sy){
    queue<State> Q;
    Q.push(State(sx,sy,0));
    step[State(sx,sy,0)] = 0;
 
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int x = s.x,y = s.y,S = s.S;
	if(y >= H){
	    return step[s];
	}
	for(int i = 0 ; i < 8 ; i++){
	    int nx = x+dx[i], ny = y+dy[i], nS = S;
	    if(!inField(nx,ny)) continue;
	    if(field[ny][nx] != 'X') continue;
	    if(num[ny][nx] >= 0 && !(S >> num[ny][nx] & 1)){
		bool can = true;
		nS |= (1<<num[ny][nx]);
		while(true){
		    nx += dx[i]; ny += dy[i];
		    if(ny >= H || (ny == H-1 && inW(nx))){
			return step[s]+1;
		    }
		    if(!inW(nx) || ny < 0){ can = false; break; }
		    if(field[ny][nx] != 'X') break; 
		    if(nS >> num[ny][nx] & 1) break; 
		    nS |= (1<<num[ny][nx]);
		}
		if(can && step.find(State(nx,ny,nS)) == step.end()){
		    step[State(nx,ny,nS)] = step[s]+1;
		    Q.push(State(nx,ny,nS));
		}
	    }
	}
    }
    return -1;
}
 
int main(){
    int x,y,n = 0;
    memset(num,-1,sizeof(num));
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	    if(field[i][j] == 'O'){
		x = j; y = i;
	    }else if(field[i][j] == 'X'){
		num[i][j] = n++;
	    }
	}
    }
    cout << bfs(x,y) << endl;
    return 0;
}
