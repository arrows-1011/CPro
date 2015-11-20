#include <iostream>
#include <queue>
#include <cstring>
 
using namespace std;
 
#define MAX 20
#define INF 1e9
 
int H,W,ax,ay,bx,by;
char field[MAX][MAX];
string str;
const int dx[] = {-1,0,0,1,0};
const int dy[] = {0,-1,1,0,0};
 
struct State{
    int sx,sy,gx,gy;
    State(int sx,int sy,int gx,int gy) : sx(sx),sy(sy),gx(gx),gy(gy) {}
};
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
int getDir(char ch){
    if(ch == '4') return 0;
    if(ch == '8') return 1;
    if(ch == '2') return 2;
    if(ch == '6') return 3;
    return 4;
}
 
void bfs(){
    int size = str.size();
    bool visited[MAX][MAX][MAX][MAX][MAX];
    memset(visited,0,sizeof(visited));
    visited[ay][ax][by][bx][0] = true;
    queue<State> Q;
    queue<int> Count;
    Q.push(State(ax,ay,bx,by));
    Count.push(0);
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int cnt = Count.front(); Count.pop();
 
	if(s.sx == s.gx && s.sy == s.gy){
	    cout << cnt << " " << s.sy << " " << s.sx << endl;
	    return;
	}
 
	int dir = getDir(str[cnt%size]);
	int Gx = s.gx + dx[dir], Gy = s.gy + dy[dir];
	if(!inField(Gy,Gx)) Gx = s.gx, Gy = s.gy;
 
	for(int i = 0 ; i < 5 ; i++){
	    int nx = s.sx + dx[i], ny = s.sy + dy[i];
	    if(!inField(ny,nx)) continue;
	    if(field[ny][nx] == '#') continue;
	    if(visited[ny][nx][Gy][Gx][(cnt+1)%size]) continue;
	    visited[ny][nx][Gy][Gx][(cnt+1)%size] = true;
	    Q.push(State(nx,ny,Gx,Gy));
	    Count.push(cnt+1);
	}
    }
    cout << "impossible" << endl;
}
 
int main(){
    while(cin >> H >> W, (H|W)){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == 'A'){
		    ax = j, ay = i;
		}else if(field[i][j] == 'B'){
		    bx = j, by = i;
		}
	    }
	}
	cin >> str;
	bfs();
    }
    return 0;
}
