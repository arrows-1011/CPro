#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
 
int H,W;
int dp[MAX][MAX];
char S[MAX][MAX];
 
bool rec(int x,int y){
    if(dp[y][x] >= 0) return dp[y][x];
    int res = 0;
    if(x+1 < W && S[y][x+1] == '.' && rec(x+1,y) == 0) res = 1;
    if(y+1 < H && S[y+1][x] == '.' && rec(x,y+1) == 0) res = 1;
    if(x+1 < W && y+1 < H && S[y+1][x+1] == '.' && rec(x+1,y+1) == 0){
	res = 1;
    }
    return (dp[y][x] = res);
}
 
int main(){
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> S[i][j];
	    dp[i][j] = -1;
	}
    }
    puts(rec(0,0) ? "First" : "Second");
    return 0;
}
