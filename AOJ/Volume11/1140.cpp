#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
 
using namespace std;
 
#define MAX 25
#define INF (1<<29)
typedef pair<int,int> P;
 
int H,W;
char field[MAX][MAX];
vector<P> vec;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
 
struct State{
    int x,y,S;
    State() {}
    State(int x,int y,int S) : x(x),y(y),S(S) {}
};
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
int bfs(int sx,int sy,int gx,int gy){
    int res = INF;
    int dist[MAX][MAX];
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    dist[i][j] = INF;
	}
    }
    dist[sy][sx] = 0;
    queue<P> Q;
    Q.push(P(sx,sy));
 
    while(!Q.empty()){
	P p = Q.front(); Q.pop();
	if(p.first == gx && p.second == gy){
	    res = dist[gy][gx];
	    break;
	}
	for(int i = 0 ; i < 4 ; i++){
	    int nx = p.first + dx[i];
	    int ny = p.second + dy[i];
	    if(!inField(ny,nx)) continue;
	    if(field[ny][nx] == 'x') continue;
	    if(dist[p.second][p.first] + 1 < dist[ny][nx]){
		dist[ny][nx] = dist[p.second][p.first] + 1;
		Q.push(P(nx,ny));
	    } 
	}
    }
 
    return res;
}
 
void solve(int x,int y){
    int size = vec.size(),ans = INF;
    int dist[MAX][MAX][1<<10];
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    for(int k = 0 ; k < 1<<size ; k++){
		dist[i][j][k] = INF;
	    }
	}
    }
    dist[y][x][0] = 0;
    queue<State> Q;
    Q.push(State(x,y,0));
    while(!Q.empty()){
	State now = Q.front(); Q.pop();
	if(__builtin_popcount(now.S) == size){
	    ans = min(ans,dist[now.y][now.x][now.S]);
	    continue;
	}
 
	for(int i = 0 ; i < size ; i++){
	    int S = now.S;
	    if(now.S >> i & 1) continue;
	    S |= 1<<i;
	    int nx = vec[i].second, ny = vec[i].first;
	    int d = bfs(now.x,now.y,nx,ny);
	    if(dist[now.y][now.x][now.S] + d < dist[ny][nx][S]){
		dist[ny][nx][S] = d + dist[now.y][now.x][now.S];;
		Q.push(State(nx,ny,S));
	    } 
	}
    }
 
    cout << (ans == INF ? -1 : ans) << endl;
}
 
int main(){
    int sx,sy;
    while(cin >> W >> H, (W | H)){
	vec.clear();
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == 'o'){
		    sx = j; sy = i;
		}else if(field[i][j] == '*'){
		    vec.push_back(P(i,j));
		}
	    }
	}
	solve(sx,sy);
    }
    return 0;
}
