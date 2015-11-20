#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
 
const int MAX = 30;
typedef pair<int,int> P;
 
int H,W;
int dist[MAX+1][MAX+1];
bool wall[MAX+1][MAX+1][4];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
 
int bfs(){
    queue<P> Que;
    Que.push(P(0,0));
 
    memset(dist,0,sizeof(dist));
    dist[0][0] = 1;
   
    while(!Que.empty()){
	P p = Que.front(); Que.pop(); 
	int y = p.first, x = p.second;
 
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
  
	    if(0 <= nx && nx < W && 0 <= ny && ny < H && 
	       !wall[y][x][i] && !dist[ny][nx]){
		dist[ny][nx] = dist[y][x] + 1;
		Que.push(P(ny,nx));
	    }
	}
    }
 
    return dist[H-1][W-1];
}
 
int main(){
    while(cin >> W >> H , W | H){
	memset(wall,false,sizeof(wall));
 
	int t;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W - 1 ; j++){
		cin >> t;      
		wall[i][j][1] = wall[i][j+1][3] = t;
	    }
	    if(i < H-1){
		for(int j = 0 ; j < W ; j++){
		    cin >> t;
		    wall[i][j][2] = wall[i+1][j][0] = t;
		}
	    }
	}
	cout << bfs() << endl;
    }
    return 0;
}
