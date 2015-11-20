#include <iostream>

using namespace std;

#define MAX 21
 
string str[MAX];
int n,m,cnt,dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
 
void dfs(int x,int y){
    str[x][y] = '#';
 
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i] , ny = y + dy[i];
	if(0 <= nx && nx < m && 0 <= ny && ny < n){
	    if(str[nx][ny] == '.'){
		cnt++;
		dfs(nx,ny);
	    }
	}
    }
}
 
int main(){
    while(cin >> n >> m , n + m){
	for(int i = 0 ; i < m ; i++){
	    cin >> str[i];
	}
     
	int x,y;
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < m ; j++){
		if(str[j][i] == '@'){
		    x = j;
		    y = i;
		    break;
		}
	    }
	}
	cnt = 1;
	dfs(x,y);
	cout << cnt << endl;
    }
    return 0;
}
