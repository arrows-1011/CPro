#include <bits/stdc++.h>
 
using namespace std;
 
int board[4][4];
 
bool inField(int x,int y){
    return (0 <= x && x < 4 && 0 <= y && y < 4);
}
 
int solve(int idx,int *x,int *y){
    if(idx == 8){ return 1; }
    int sx,sy;
    for(int i = 0 ; i < 4 ; i++){
	bool found = false;
	for(int j = 0 ; j < 4 ; j++){
	    if(board[i][j] == -1){
		sx = j; sy = i;
		found = true;
		break;
	    }
	}
	if(found){ break; }
    }
    int res = 0;
    for(int i = 0 ; i < 4 ; i++){
	int tx = sx+x[i],ty = sy+y[i];
	if(!inField(tx,ty) || board[ty][tx] != -1){
	    continue;
	}
	board[sy][sx] = board[ty][tx] = idx;
	res += solve(idx+1,x,y);
	board[sy][sx] = board[ty][tx] = -1;
    }
    return res;
}
 
int main(){
    int x[4],y[4];
    while(cin >> x[0] >> y[0], x[0] < 4){
	for(int i = 1 ; i < 4 ; i++){
	    cin >> x[i] >> y[i];
	}
	memset(board,-1,sizeof(board));
	cout << solve(0,x,y) << endl;
    }
    return 0;
}
