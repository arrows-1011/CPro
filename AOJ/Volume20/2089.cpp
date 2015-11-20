#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 30
#define INF (1<<29)
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
 
int H,W,sx,sy,gx,gy,cnt;
char field[MAX][MAX];
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
 
struct State{
    int x,y,S;
    State(){}
    State(int x,int y,int S) : x(x),y(y),S(S) {}
};
 
bool isValid(int x,int y){
    if(x < 0 || x >= W || y < 0 || y >= H) return false;
    if(field[y][x] == '#') return false;
    return true;
}
 
int solve(){
    queue<State> Q;
    Q.push(State(sx,sy,0));
    map<piii,int> dist;
    dist[piii(pii(sx,sy),0)] = 0;
 
    while(!Q.empty()){
	State now = Q.front(); Q.pop();
	int x = now.x, y = now.y, S = now.S;
	piii pp = piii(pii(x,y),S);
     
	if(x == gx && y == gy){
	    return dist[pp];
	}
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i], ny = y + dy[i];
	    if(!isValid(nx,ny)) continue;
	    piii cp = piii(pii(nx,ny),S);
 
	    if(islower(field[ny][nx])){
		int p = field[ny][nx]-'a';
		int nS = S;
		if((S >> p) & 1){
		    nS -= (1<<p);
		}else{
		    nS |= (1<<p);
		}
		cp.second = nS;
		if(dist[pp] + 1 < dist[cp] || dist[cp] == 0){
		    dist[cp] = dist[pp] + 1;
		    Q.push(State(nx,ny,nS));
		}
	    }else if(isupper(field[ny][nx])){
		int p = field[ny][nx]-'A';
		if((S >> p) & 1){
		    if(dist[pp] + 1 < dist[cp] || dist[cp] == 0){
			dist[cp] = dist[pp] + 1;
			Q.push(State(nx,ny,S));
		    }
		}
	    }else{
		if(dist[pp] + 1 < dist[cp] || dist[cp] == 0){
		    dist[cp] = dist[pp] + 1;
		    Q.push(State(nx,ny,S));
		}
	    } 
	}
    }
    return -1;
}
 
int main(){
    while(cin >> W >> H,(W | H)){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == '@'){
		    field[i][j] = '.';
		    sx = j; sy = i;
		}else if(field[i][j] == '<'){
		    gx = j; gy = i;
		    field[i][j] = '.';
		}
	    }     
	}
	cout << solve() << endl;
    }
    return 0;
}
