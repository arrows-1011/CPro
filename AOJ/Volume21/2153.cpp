#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 51
 
struct State{
    int x1,y1,x2,y2;
    State(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};
 
int H, W;
char f1[MAX][MAX], f2[MAX][MAX];
bool vis[MAX][MAX][MAX][MAX];
const int lx[] = {0,-1,1,0};
const int ly[] = {-1,0,0,1};
const int rx[] = {0,1,-1,0};
const int ry[] = {-1,0,0,1};
 
bool inField(int y, int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
bool bfs(int Lx, int Ly, int Rx, int Ry){
    memset(vis, false, sizeof(vis));
    queue<State> Q;
    Q.push(State(Lx, Ly, Rx, Ry));
 
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
 
	if(f1[s.y1][s.x1] == '%' && f2[s.y2][s.x2] == '%'){
	    return true;
	}
	for(int i = 0 ; i < 4 ; i++){
	    int nlx = s.x1 + lx[i], nly = s.y1 + ly[i];
	    int nrx = s.x2 + rx[i], nry = s.y2 + ry[i];
 
	    if(!inField(nly, nlx) || f1[nly][nlx] == '#'){
		nlx = s.x1;
		nly = s.y1;
	    }
	    if(!inField(nry, nrx) || f2[nry][nrx] == '#'){
		nrx = s.x2;
		nry = s.y2;
	    }
 
	    if((f1[nly][nlx] == '%' && f2[nry][nrx] != '%') ||
	       (f1[nly][nlx] != '%' && f2[nry][nrx] == '%')) continue;
 
	    if(vis[nly][nlx][nry][nrx]) continue;
	    vis[nly][nlx][nry][nrx] = true;
	    Q.push(State(nlx, nly, nrx, nry));
	}
    }
 
    return false;
}
 
int main(){
    while(cin >> W >> H, (W | H)){
	string str;
	int Lx, Ly, Rx, Ry;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < 2 ; j++){
		cin >> str;
		for(int k = 0 ; k < W ; k++){
		    if(j % 2 == 0){
			f1[i][k] = str[k];
			if(f1[i][k] == 'L'){
			    Lx = k;
			    Ly = i;
			}
		    }else{
			f2[i][k] = str[k];
			if(f2[i][k] == 'R'){
			    Rx = k;
			    Ry = i;
			}
		    }
		}
	    }
	}
	cout << (bfs(Lx, Ly, Rx, Ry) ? "Yes" : "No") << endl;
    }
    return 0;
}
