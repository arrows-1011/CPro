#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
#define MAX 120
#define INF 1e9
 
int H, W;
char field[MAX][MAX];
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
 
bool inField(int y, int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
bool check(int y, int x){
    if(y == 0 || y == H-1) return true;
    if(x == 0 || x == W-1) return true;
    return false;
}
 
void bfs(int y, int x){
    int ans = INF;
    int cost[MAX][MAX];
    fill(cost[0], cost[MAX], INF);
    queue<int> nowx, nowy;
    nowx.push(x); nowy.push(y); 
    cost[y][x] = 0;
 
    while(!nowx.empty()){
	int xx = nowx.front(); nowx.pop();
	int yy = nowy.front(); nowy.pop();
	int cnt = cost[yy][xx];
 
	for(int i = 0 ; i < 4 ; i++){
	    int nx = xx + dx[i];
	    int ny = yy + dy[i];
 
	    if(!inField(ny, nx)) continue;
	    if(check(ny, nx)){
		if(field[yy][xx] != '#' && field[ny][nx] == '#'){
		    cost[ny][nx] = min(cost[ny][nx], cnt+1);
		}else{
		    cost[ny][nx] = min(cost[ny][nx], cnt);
		}
		continue;
	    }
	    int ncnt = cnt;
	    if(field[yy][xx] != '#' && field[ny][nx] == '#') ncnt++;
	    if(ncnt < cost[ny][nx]){
		cost[ny][nx] = ncnt;
		nowx.push(nx); nowy.push(ny);
	    }
	}
    }
    for(int i = 0 ; i < H ; i++){
	ans = min(ans, cost[i][0]);
	ans = min(ans, cost[i][W-1]);
    }
    for(int i = 0 ; i < W ; i++){
	ans = min(ans, cost[0][i]);
	ans = min(ans, cost[H-1][i]);
    }
    cout << ans << endl;
}
 
int main(){
    int sx, sy;
    while(cin >> W >> H, (W | H)){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == '&'){
		    sx = j; sy = i;
		}
	    }
	}  
	bfs(sy, sx);
    }
    return 0;
}
