#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 55
#define MAX_W 55
 
int H,W,sx,sy,gx,gy;
bool visited[MAX_H][MAX_W];
char field[MAX_H][MAX_W];
set<char> st;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
 
void getPos(int x,int y,char ch){
    if(visited[y][x]) return;
    visited[y][x] = true;
    if(field[y][x] == ch){
	sx = min(sx,x); gx = max(gx,x);
	sy = min(sy,y); gy = max(gy,y);
    }
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(0 <= nx && nx < W && 0 <= ny && ny < H){
	    getPos(nx,ny,ch);
	}
    }
}
 
bool remove(char ch){
    for(int i = sy ; i <= gy ; i++){
	for(int j = sx ; j <= gx ; j++){
	    if(field[i][j] != ch && field[i][j] != '*'){
		return false;
	    }
	}
    }
    return true;
}
 
void change(){
    for(int i = sy ; i <= gy ; i++){
	for(int j = sx ; j <= gx ; j++){
	    field[i][j] = '*';
	}
    }
}
 
bool check(){
    int N = st.size();
    while(N--){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		if(field[i][j] == '.') continue;
		if(field[i][j] == '*') continue;
		memset(visited,false,sizeof(visited));
		sx = sy = 1e9; gx = gy = 0;
		getPos(j,i,field[i][j]);
		if(remove(field[i][j])){
		    change();
		    goto next;
		}
	    }
	}
	return false;
    next:;
    }
    return true;
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	cin >> H >> W;
	st.clear();
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(isupper(field[i][j])){
		    st.insert(field[i][j]);
		}
	    }
	}
	cout << (check() ? "SAFE" : "SUSPICIOUS") << endl;
    }
    return 0;
}
