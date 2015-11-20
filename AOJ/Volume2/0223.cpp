#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
struct State{
    int tx, ty, kx, ky;
    State(int tx, int ty, int kx, int ky) : tx(tx), ty(ty), kx(kx), ky(ky) {} 
};
 
#define MAX 51
#define INF 1e9
 
int H, W, tx, ty, kx, ky;
int field[MAX][MAX];
const int ttx[] = {-1,0,0,1};
const int tty[] = {0,-1,1,0};
const int kkx[] = {1,0,0,-1};
const int kky[] = {0,1,-1,0};
 
bool inField(int y, int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
int bfs(){
    bool vis[MAX][MAX][MAX][MAX];
    memset(vis, false, sizeof(vis));
    vis[ty][tx][ky][kx] = true;
    queue<State> Q;
    Q.push(State(tx,ty,kx,ky));
    queue<int> cnt;
    cnt.push(0);
 
    int res = INF;
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int _cnt = cnt.front(); cnt.pop();
 
	if(_cnt == 100) break;
	if(s.tx == s.kx && s.ty == s.ky){
	    res = min(res, _cnt);
	    break;
	}
 
	for(int i = 0 ; i < 4 ; i++){
	    int ntx = s.tx + ttx[i], nty = s.ty + tty[i];
	    int nkx = s.kx + kkx[i], nky = s.ky + kky[i];
 
	    if(!inField(nty, ntx) || field[nty][ntx] == 1){
		ntx = s.tx, nty = s.ty;
	    }
	    if(!inField(nky, nkx) || field[nky][nkx] == 1){
		nkx = s.kx, nky = s.ky;
	    }
 
	    if(vis[nty][ntx][nky][nkx]) continue;
	    vis[nty][ntx][nky][nkx] = true;
	    Q.push(State(ntx, nty, nkx, nky));
	    cnt.push(_cnt+1);
	}
    }
    return res;
}
 
int main(){
    while(cin >> W >> H, (W | H)){
	cin >> tx >> ty >> kx >> ky;
	tx--, ty--, kx--, ky--;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
	    }
	}
	int res = bfs();
	if(res == INF){
	    cout << "NA" << endl;
	}else{
	    cout << res << endl;
	}
    }
    return 0;
}
