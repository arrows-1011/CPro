#include <bits/stdc++.h>
 
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
 
int H,W,N,x,y,d;
char f[20][20],c;
char dir[]={'U','D','L','R'};
char m[]={'^','v','<','>'};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool flg;
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
void shoot(){
    int tx = x, ty = y;
    while(true){
	int nx = tx + dx[d],ny = ty + dy[d];
	if(!inField(ny,nx) || f[ny][nx] == '#') return;
	if(f[ny][nx] == '*'){ f[ny][nx] = '.'; return; }
	tx = nx, ty = ny;
    }
}
 
void move(){
    int nx = x + dx[d],ny = y + dy[d];
    f[y][x] = m[d];
    if(!inField(ny,nx) || f[ny][nx] == '-' ||
       f[ny][nx] == '#' || f[ny][nx] == '*') return;
    f[y][x] = '.'; f[ny][nx] = m[d];
    y = ny, x = nx;
}
 
void print(){
    rep(i,H){
	rep(j,W){
	    cout << f[i][j];
	}
	cout << endl;
    }
}
 
void solve(){
    cin >> N;
    rep(i,N){
    
	cin >> c;
	if(c == 'S'){
	    rep(j,4){
		if(m[j] == f[y][x]){
		    d = j;
		    break;
		}
	    }
	    shoot();
	}else{
	    rep(j,4){
		if(dir[j] == c){
		    d = j;
		    break;
		}
	    }
	    move();
	}
    }
    print();
}
 
int main(){
    int Tc;
    cin >> Tc;
    while(Tc--){
	if(flg) cout << endl; flg = true;
	cin >> H >> W;
	rep(i,H) rep(j,W){
	    cin >> f[i][j];
	    if(f[i][j] == '<' || f[i][j] == '>' ||
	       f[i][j] == '^' || f[i][j] == 'v'){
		y = i; x = j;
	    }
	}
	solve();
    }
    return 0;
}
