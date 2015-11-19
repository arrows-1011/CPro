#include <bits/stdc++.h>
  
using namespace std;
  
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
const char d[4] = {'L','U','R','D'};
  
int main(){
    char ch;
    bool G[6][6][4];
    memset(G,false,sizeof(G));
    for(int i = 0 ; i < 9 ; i++){
	int d = i%2;
	for(int j = 0 ; j < 4+d ; j++){
	    cin >> ch;
	    if(ch == '1'){
		if(d%2){
		    G[i/2+1][j][2] = G[i/2+1][j+1][0] = true;
		}else{
		    G[i/2][j+1][3] = G[i/2+1][j+1][1] = true;
		}
	    }
	}
    }
    int x = 1,y = 0,dir = 2;
    string ans;
    while(true){
	if(!x && !y) break;
	ans += d[dir];
	int rh = (dir+1)%4;
	if(G[y][x][dir]){
	    dir--;
	    dir = (dir == -1 ? 3 : dir);
	}else if(!G[y+dy[dir]][x+dx[dir]][rh]){
	    x += dx[dir], y += dy[dir];
	    if(!x && !y) break;
	    x += dx[rh], y += dy[rh];
	    dir = rh;
	    int nrh = (rh+1)%4;
	    if(!G[y][x][nrh] && !(!x && !y)){
		x += dx[nrh], y += dy[nrh];
		dir = nrh;
	    }
	}else{
	    x += dx[dir]; y += dy[dir];
	}
    }
    cout << ans << endl;
    return 0;
}
