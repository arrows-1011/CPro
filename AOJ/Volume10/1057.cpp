#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 10
#define MAX_W 10
 
struct Dice{
    int tmp,d[6];
    Dice(){
	for(int i = 0 ; i < 6 ; i++){
	    d[i] = i;
	}
    }
    void rollN(){
	tmp = d[0];
	d[0] = d[1];
	d[1] = d[5];
	d[5] = d[4];
	d[4] = tmp;
    }
    void rollE(){
	tmp = d[0];
	d[0] = d[3];
	d[3] = d[5];
	d[5] = d[2];
	d[2] = tmp;
    }
    void rollS(){
	tmp = d[0];
	d[0] = d[4];
	d[4] = d[5];
	d[5] = d[1];
	d[1] = tmp;
    }
    void rollW(){
	tmp = d[0];
	d[0] = d[2];
	d[2] = d[5];
	d[5] = d[3];
	d[3] = tmp;
    }
};
 
struct State{
    int cost,x,y;
    Dice d;
    bool operator < (const State &s)const{
	return cost > s.cost;
    }
};
 
int main(){
    int H,W;
    while(cin >> H >> W, H){
	int field[MAX_H][MAX_W];
	int sx,sy,gx,gy;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
	    }
	}
	cin >> sy >> sx >> gy >> gx;
	int cost[MAX_H][MAX_W][6][6][6];
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		for(int k = 0 ; k < 6 ; k++){
		    for(int l = 0 ; l < 6 ; l++){
			for(int m = 0 ; m < 6 ; m++){
			    cost[i][j][k][l][m] = 1e9;
			}
		    }
		}
	    }
	}
	Dice die;
	cost[sy][sx][die.d[0]][die.d[1]][die.d[2]] = 0;
	priority_queue<State> Q;
	Q.push((State){0,sx,sy,die});
	const int dx[] = {-1,0,1,0};
	const int dy[] = {0,-1,0,1};
	while(!Q.empty()){
	    State s = Q.top(); Q.pop();
	    int x = s.x, y = s.y;
	    int ncost = cost[y][x][s.d.d[0]][s.d.d[1]][s.d.d[2]];
	    if(ncost < s.cost){ continue; }
	    if(x == gx && y == gy){
		cout << s.cost << endl;
		break;
	    }
	    for(int i = 0 ; i < 4 ; i++){
		int nx = x + dx[i], ny = y + dy[i];
		Dice d = s.d;
		if(0 > nx || nx >= W || 0 > ny || ny >= H){
		    continue;
		}
		switch(i){
		case 0:
		    d.rollW();
		    break;
		case 1:
		    d.rollN();
		    break;
		case 2:
		    d.rollE();
		    break;
		case 3:
		    d.rollS();
		    break;
		}
		int p = (d.d[5]+1)*field[ny][nx];
		if(s.cost + p < cost[ny][nx][d.d[0]][d.d[1]][d.d[2]]){
		    cost[ny][nx][d.d[0]][d.d[1]][d.d[2]] = s.cost + p;
		    Q.push((State){cost[ny][nx][d.d[0]][d.d[1]][d.d[2]],nx,ny,d});
		}
	    }
	}
    }
    return 0;
}
