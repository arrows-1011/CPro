#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
 
using namespace std;
 
#define MAX 25
 
int H,W,mem;
char field[MAX][MAX];
bool visited[MAX][MAX][16][4];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
 
void Nextpos(int &y,int &x){
    if(x >= W){
	x = 0;
    }else if(y >= H){
	y = 0;
    }else if(x < 0){
	x = W-1;
    }else if(y < 0){
	y = H-1;
    }
}
 
bool solve(int y,int x,int dir){
    if(x >= 0 && field[y][x] == '@') return true;
    if(x >= 0 && visited[y][x][mem][dir]) return false;
    if(x >= 0) visited[y][x][mem][dir] = true;
 
    int nx = x + dx[dir], ny = y + dy[dir];
    Nextpos(ny,nx);
   
    if(isdigit(field[ny][nx])){
	mem = field[ny][nx] - '0';
    }else{
	switch(field[ny][nx]){
	case '>':
	    dir = 0;
	    break;
	case 'v':
	    dir = 1;
	    break;
	case '<':
	    dir = 2;
	    break;
	case '^':
	    dir = 3;
	    break;
	case '_':
	    dir = (mem == 0 ? 0 : 2);
	    break;
	case '|':
	    dir = (mem == 0 ? 1 : 3);
	    break;
	case '?':
	    for(int i = 0 ; i < 4 ; i++){
		if(solve(ny,nx,i)) return true;
	    }
	    break;
	case '+':
	    mem = (mem == 15 ? 0 : mem+1);
	    break;
	case '-':
	    mem = (mem == 0 ? 15 : mem-1);
	    break;
	}
    }
    if(solve(ny,nx,dir)) return true;
    return false;
}
 
int main(){
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	}
    }
    mem = 0;
    memset(visited,false,sizeof(visited));
    cout << (solve(0,-1,0) ? "YES" : "NO") << endl;
    return 0;
}
