#include <iostream>
#include <queue>
#include <cstring>
 
using namespace std;
 
#define MAX 151
#define INF 1e9
 
struct P{
    int x, y, d;
    P(int x, int y, int d){
	this->x = x;
	this->y = y;
	this->d = d;
    }
};
 
int t, sx, sy;
bool impossible[MAX][MAX];
int dist[MAX][MAX];
const int dx[] = {-1,0,0,-1,1,1};
const int dy[] = {-1,-1,1,0,0,1};
 
int bfs(int x, int y){
    bool visited[MAX][MAX];
    memset(visited,false,sizeof(visited));
    fill(dist[0],dist[MAX],INF);
 
    queue<P> que;
    que.push(P(x,y,0));
    dist[x][y] = 0;
 
    while(!que.empty()){
	P p = que.front(); que.pop();
 
	if(impossible[p.x][p.y] || p.d > t || 
	   visited[p.x][p.y]){
	    continue;
	}
	visited[p.x][p.y] = true;
 
	for(int i = 0 ; i < 6 ; i++){
	    int nx = p.x + dx[i];
	    int ny = p.y + dy[i];
       
	    if(impossible[nx][ny] || dist[nx][ny] != INF){
		continue;
	    }
 
	    dist[nx][ny] = dist[p.x][p.y] + 1;
	    que.push(P(nx,ny,dist[nx][ny]));
	}
    }
 
    int res = 0;
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    if(dist[i][j] <= t){
		res++;
	    }
	}
    }
    return res;
}
 
int main(){
    int n, x, y;
 
    while(cin >> t >> n , (t | n)){
	memset(impossible,false,sizeof(impossible));
	for(int i = 0 ; i < n ; i++){
	    cin >> x >> y;
	    x += 75, y += 75;
	    impossible[x][y] = true;
	}
	cin >> sx >> sy;
	cout << bfs(sx+75, sy+75) << endl;
    }
    return 0;
}
