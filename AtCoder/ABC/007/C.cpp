#include <iostream>
#include <queue>
#include <cstring>
 
using namespace std;
 
#define INF 1000000
typedef pair<int,int> P;
 
int main(){
    int H,W,sx,sy,gx,gy;
    char field[50][50];
    cin >> H >> W;
    cin >> sy >> sx; sy--; sx--;
    cin >> gy >> gx; gy--; gx--;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	}
    }
    queue<P> Q;
    Q.push(P(sx,sy));
    int d[50][50];
    fill(d[0],d[0]+50*50,INF);
    d[sy][sx] = 0;
 
    while(!Q.empty()){
	P p = Q.front(); Q.pop();
	int x = p.first, y = p.second;
	if(x == gx && y == gy){
	    cout << d[gy][gx] << endl;
	    break;
	}
	const int dx[4] = {-1,0,1,0};
	const int dy[4] = {0,-1,0,1};
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    if(field[ny][nx] == '#'){
		continue;
	    }
	    if(d[y][x]+1 < d[ny][nx]){
		d[ny][nx] = d[y][x]+1;
		Q.push(P(nx,ny));
	    }
	}
    }
    return 0;
}
