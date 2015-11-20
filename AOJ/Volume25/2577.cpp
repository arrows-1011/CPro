#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 55
 
int H,W,D,N,r[10],X,Y;
char field[MAX][MAX];
bool visited[MAX][MAX];
bool treasure[MAX][MAX];
bool possible[MAX][MAX];
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
typedef pair<int,int> P;
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
bool check(int y,int x,int r){
    int x1 = x - r, x2 = x + r;
    int y1 = y - r, y2 = y + r;
    return x1 <= X && X <= x2 && y1 <= Y && Y <= y2;
}
 
void search(int y,int x,int s){
    if(visited[y][x]) return;
    visited[y][x] = true;
 
    if(s == 0){
	if(check(y,x,r[0]) && field[y][x] != '#'){
	    treasure[y][x] &= true;
	}else{
	    treasure[y][x] &= false;
	}
    }else if(s == D){
	if(!check(y,x,r[D-1]) && field[y][x] != '#'){
	    treasure[y][x] &= true;
	}else{
	    treasure[y][x] &= false;
	}
    }else{
	if(!check(y,x,r[s-1]) && check(y,x,r[s]) && field[y][x] != '#'){
	    treasure[y][x] &= true;
	}else{
	    treasure[y][x] &= false;
	}
    }
 
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(!inField(ny,nx)) continue;    
	search(ny,nx,s);
    }
}
 
void bfs(int y,int x){
    memset(possible,false,sizeof(possible));
    queue<P> Q; Q.push(P(y,x));
    while(!Q.empty()){
	P now = Q.front(); Q.pop();
	x = now.second; y = now.first;
	if(possible[y][x]) continue;
	possible[y][x] = true;
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    if(!inField(ny,nx) || field[ny][nx] == '#') continue;
	    Q.push(P(ny,nx));
	}
    }
}
 
int main(){
    cin >> H >> W >> D >> N;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	    if(field[i][j] == 'D'){
		X = j; Y = i;
	    }
	    treasure[i][j] = true;
	}
    }
    bfs(Y,X);
    for(int i = 0 ; i < D ; i++){
	cin >> r[i];
    }
    for(int i = 0 ; i < N ; i++){
	int x,y,s;
	cin >> x >> y >> s; 
	memset(visited,false,sizeof(visited));
	X = x, Y = y; 
	search(y,x,s);
    }
    bool broken = true, c1 = false, c2 = false;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    if(treasure[i][j]) broken = false;
	    if(possible[i][j] && treasure[i][j]) c1 = true;
	    if(!possible[i][j] && treasure[i][j]) c2 = true;
	}
    }
 
    if(broken){
	cout << "Broken" << endl;
    }else if(c1 && c2){
	cout << "Unknown" << endl;
    }else{
	cout << (c1 ? "Yes" : "No") << endl;
    }
    return 0;
}
