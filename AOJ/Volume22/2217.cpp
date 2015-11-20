#include <iostream>
#include <vector>
#include <cstring>
 
using namespace std;
 
#define MAX 100
 
int tx, ty, ans;
int n, X[MAX][MAX], Y[MAX][MAX];
bool visited[MAX][MAX], found[MAX][MAX];
bool used[MAX][MAX], flg;
 
void rec(int x, int y){
    if(visited[x][y]){
	if(!found[x][y] && tx == x && ty == y){
	    found[x][y] = flg = true;
	    ans++;
	} 
	return;
    }
    visited[x][y] = true;
    rec(X[x][y],Y[x][y]);
}
 
void draw(int x,int y){
    if(tx == x && ty == y){
	return;
    }
    used[x][y] = true;
    draw(X[x][y],Y[x][y]);
}
 
int main(){
    while(cin >> n ,n){
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		cin >> X[j][i] >> Y[j][i];
	    }
	}
 
	ans = 0;
	memset(found,false,sizeof(found));
	memset(used,false,sizeof(used));
	for(int i = 0 ; i < n ; i++){ 
	    for(int j = 0 ; j < n ; j++){
		memset(visited,false,sizeof(visited));
		if(!used[i][j]){
		    flg = false;
		    visited[i][j] = true;
		    tx = i, ty = j;
		    rec(X[i][j], Y[i][j]);
		    if(flg){
			draw(X[i][j], Y[i][j]);
		    }
		}
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
