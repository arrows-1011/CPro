#include <iostream>
#include <algorithm>
 
using namespace std;

#define MAX 90
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int W,H;
int field[MAX][MAX];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
 
int rec(int x,int y){
    int res = 0;
 
    rep(i,4){
	int nx = x + dx[i];
	int ny = y + dy[i];
    
	if(0 <= nx && nx < H && 0 <= ny && ny < W){
	    if(field[nx][ny]){
		field[nx][ny] = 0;
		res = max(res,rec(nx,ny)+1);
		field[nx][ny] = 1;
	    }
	}
    }
    return res;
}
 
int main(){
    while(cin >> W >> H , W | H){
	rep(i,H){
	    rep(j,W){
		cin >> field[i][j];
	    }
	}
 
	int ans = -1;
	rep(i,H){
	    rep(j,W){
		ans = max(ans,rec(i,j));
	    }
	}  
	cout << ans << endl;
    }
    return 0;
}
