#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 550
#define MAX_W 550
#define MAX_D 4
#define INF 1e9
 
struct State{
    int d,x,y;
    State(int d,int x,int y) :
	d(d),x(x),y(y) {}
   
    bool operator > (const State &s)const{
	return d > s.d;
    }
};
 
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
 
struct TroddenCable{
    int H,W,N,sx,sy,gx,gy;
    int cost[MAX_H][MAX_W][MAX_D];
    int d[MAX_H][MAX_W];
 
    TroddenCable(){
	for(int i = 0 ; i < MAX_H ; i++){
	    for(int j = 0 ; j < MAX_W ; j++){
		d[i][j] = INF;
		for(int k = 0 ; k < MAX_D ; k++){
		    cost[i][j][k] = 0;
		}
	    }
	}
    }
 
    int getDir(char x){
	if(x == 'L') return 0; 
	if(x == 'U') return 1; 
	if(x == 'R') return 2; 
	if(x == 'D') return 3; 
	return -1;
    }
 
    void input(){
	int x,y,T;
	string S;
	cin >> W >> H >> N;
	cin >> sx >> sy >> gx >> gy;
	for(int i = 0 ; i < N ; i++){
	    cin >> x >> y >> T;
	    cin >> S;
	    for(int j = 0 ; j < T ; j++){
		for(int k = 0 ; k < (int)S.size() ; k++){
		    int _dir = getDir(S[k]);
		    int nx = x + dx[_dir], ny = y + dy[_dir];
		    if(0 > nx || nx >= W || 0 > ny || ny >= H){
			continue;
		    }
		    if(x == nx){
			cost[max(y,ny)][x][2]++;
			cost[max(y,ny)][x+1][0]++;
		    }else if(y == ny){
			cost[y][max(x,nx)][3]++;
			cost[y+1][max(x,nx)][1]++;
		    }
		    x = nx; y = ny;
		}
	    }
	}
    }
 
    int solve(){
	priority_queue<State,vector<State>,greater<State> > Q;
	Q.push(State(0,sx,sy));
	d[sy][sx] = 0;
	while(!Q.empty()){
	    State s = Q.top(); Q.pop();
	    int x = s.x,y = s.y;
	    if(d[y][x] < s.d) continue;
	    if(x == gx && y == gy) return d[y][x]; 
	    for(int i = 0 ; i < 4 ; i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(0 > nx || nx > W || 0 > ny || ny > H) continue; 
		if(d[y][x] + cost[y][x][i] < d[ny][nx]){
		    d[ny][nx] = d[y][x] + cost[y][x][i];
		    Q.push(State(d[ny][nx],nx,ny));
		}
	    }
	}
	return -1;
    }
 
    void run(){
	input();
	cout << solve() << endl;
    }
};
 
int main(){
    TroddenCable tc;
    tc.run();
    return 0;
}
