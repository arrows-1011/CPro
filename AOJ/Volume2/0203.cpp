#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MAX 20
 
int W,H;
int arr[MAX][MAX];
int dp[MAX][MAX];
const int dx[] = {-1,0,1};
const int dy[] = {1,1,1};
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
int solve(int y,int x){
    if(y == H-1){
	if(arr[y][x] == 0 || arr[y][x] == 2){
	    return 1;
	}else{
	    return 0;
	}
    }
    if(dp[y][x] != -1) return dp[y][x];
 
    int res = 0;
    if(arr[y][x] != 2){
	for(int i = 0 ; i < 3 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    if(!inField(ny,nx)) continue;
	    if(arr[ny][nx] == 1) continue;
	    if(arr[ny][nx] == 0){
		res += solve(ny,nx);
	    }else{
		if(x == nx){
		    res += solve(ny,nx);
		}
	    }
	}
    }else{
	int nx = x, ny = y + 2;
	if(!inField(ny,nx)) return 1;
	if(arr[ny][nx] == 1) return 0;
	res += solve(ny,nx);
    }
    return dp[y][x] = res;
}
 
int main(){
    while(cin >> W >> H, (W | H)){
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> arr[i][j];
		dp[i][j] = -1;
	    }
	}
	int res = 0;
	for(int i = 0 ; i < W ; i++){
	    if(arr[0][i] == 0){
		res += solve(0,i);
	    }
	}
	cout << res << endl;
    }
    return 0;
}
