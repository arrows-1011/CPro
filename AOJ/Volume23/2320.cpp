#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 110
#define MAX_W 110
typedef long long ll;
 
ll H,W,L;
char field[MAX_H][MAX_W];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
 
char getDir(int x){
    if(x == 0) return 'W'; 
    if(x == 1) return 'N'; 
    if(x == 2) return 'E'; 
    if(x == 3) return 'S'; 
}
 
int getDir(char ch){
    if(ch == 'W') return 0; 
    if(ch == 'N') return 1; 
    if(ch == 'E') return 2; 
    if(ch == 'S') return 3; 
}
 
bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}
 
void solve(int x,int y,int dir){
    int d[MAX_H][MAX_W][4];
    memset(d,-1,sizeof(d));
    d[y][x][dir] = 0;
 
    while(L > 0){
	int nx = x + dx[dir],ny = y + dy[dir];
	if(!inField(nx,ny) || field[ny][nx] == '#'){
	    int ndir = (dir+1) % 4;
	    if(d[y][x][ndir] == -1){
		d[y][x][ndir] = d[y][x][dir];
	    }else{
		int diff = d[y][x][dir]-d[y][x][ndir];
		if(diff > 0 && L >= diff){
		    L %= diff;
		}
	    }
	    if(L != 0){
		dir = ndir;
	    }
	}else{
	    if(d[ny][nx][dir] == -1){
		d[ny][nx][dir] = d[y][x][dir]+1;
		L--;
	    }else{
		L--;
		int diff = d[y][x][dir]+1-d[ny][nx][dir];
		if(diff > 0 && L >= diff){
		    L %= diff;
		}
	    }
	    x = nx; y = ny;
	}
    }
    cout << y+1 << " " << x+1 << " " << getDir(dir) << endl;
}
 
bool check(char ch){
    if(ch == '.' || ch == '#'){
	return false;
    }
    return true;
}
 
int main(){
    int sx,sy,dir;
    while(true){
	cin >> H >> W >> L;
	if(H == 0 && W == 0 && L == 0){
	    break;
	}
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(check(field[i][j])){
		    sx = j; sy = i;
		    dir = getDir(field[i][j]);
		    field[i][j] = '.';
		}
	    }
	}
	solve(sx,sy,dir);
    }
    return 0;
}
