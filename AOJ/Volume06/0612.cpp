#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 1010
#define MAX_W 1010
 
struct P{
    int x,y;
    P(int x,int y) : x(x), y(y) {}
};
 
bool inField(int x,int y,int H,int W){
    return (0 <= x && x < W && 0 <= y && y < H);
}
 
int main(){
    int H,W,arr[MAX_H][MAX_W];
    char ch;
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> ch;
	    arr[i][j] = (ch == '.' ? -1 : ch-'0');
	}
    }
    int cnt[MAX_H][MAX_W];
    memset(cnt,0,sizeof(cnt));
    const int dx[8] = {-1,-1,-1,0,0,1,1,1};
    const int dy[8] = {-1,0,1,-1,1,-1,0,1};
    queue<P> Q;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    if(arr[i][j] == -1){ continue; }
	    for(int k = 0 ; k < 8 ; k++){
		int nx = j + dx[k];
		int ny = i + dy[k];
		if(!inField(nx,ny,H,W)){ continue; }
		if(arr[ny][nx] == -1){
		    cnt[i][j]++;
		}
	    }
	    if(arr[i][j] <= cnt[i][j]){
		Q.push(P(j,i));
	    }
	}
    }
    int res = 0;
    while(!Q.empty()){
	queue<P> nQ;
	while(!Q.empty()){
	    P p = Q.front(); Q.pop();
	    for(int i = 0 ; i < 8 ; i++){
		int nx = p.x + dx[i];
		int ny = p.y + dy[i];
		if(!inField(nx,ny,H,W)){ continue; }
		if(arr[ny][nx] == -1){ continue; }
		if(arr[ny][nx] <= cnt[ny][nx]){ continue; }
		cnt[ny][nx]++;
		if(arr[ny][nx] <= cnt[ny][nx]){
		    nQ.push(P(nx,ny));
		}
	    }
	}
	Q = nQ;
	res++;
    }
    cout << res << endl;
    return 0;
}
