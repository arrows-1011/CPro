#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MAX 15
 
int H,W;
char field[MAX][MAX];
string ans;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
const char mark[] = {'U','R','D','L'};
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
int getDir(char ch){
    if(ch == 'U') return 0;
    if(ch == 'R') return 1;
    if(ch == 'D') return 2;
    if(ch == 'L') return 3;
    return -1;
}
 
void solve(int y,int x,int dir,int cnt,string s){
    if(cnt == 0){
	ans = s;
	return;
    }
 
    for(int i = 0 ; i < 4 ; i++){
	int nx = x, ny = y;
	if(dir == 0 && i == 2) continue;
	if(dir == 1 && i == 3) continue;
	if(dir == 2 && i == 0) continue;
	if(dir == 3 && i == 1) continue;
 
	while(inField(ny,nx)){
	    nx += dx[i];
	    ny += dy[i];
	    if(field[ny][nx] == 'o'){
		field[ny][nx] = '.';
		solve(ny,nx,i,cnt-1,s+mark[i]);
		field[ny][nx] = 'o';
		break;
	    }
	}
    }
}
 
int main(){
    int x,y,dir,cnt = 0;
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	    int num = getDir(field[i][j]);
	    if(num != -1){
		x = j, y = i; dir = num;
	    }else if(field[i][j] == 'o'){
		cnt++;
	    }
	}
    }
    field[y][x] = '.';
    solve(y,x,dir,cnt,"");
    cout << ans << endl;
    return 0;
}
