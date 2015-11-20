#include <iostream>
#include <cstring>
 
using namespace std;
 
char field[12][6],tmp[12][6];
bool visited[12][6];
int Bcnt;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
 
bool inField(int y,int x){
    return 0 <= y && y < 12 && 0 <= x && x < 6;
}
 
void CountBlock(int y,int x,char B){
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i], ny = y + dy[i];
	if(!inField(ny,nx)) continue;
	if(visited[ny][nx]) continue;
	if(field[ny][nx] == B){
	    visited[ny][nx] = true;
	    Bcnt++;
	    CountBlock(ny,nx,B);
	}
    }
}
 
void remove(int y,int x,char B){
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i], ny = y + dy[i];
	if(!inField(ny,nx)) continue;
	if(field[ny][nx] == B){
	    field[ny][nx] = '.';
	    remove(ny,nx,B);
	}else if(field[ny][nx] == 'O'){
	    field[ny][nx] = '.';
	}
    }
}
 
void FallBlock(){
    for(int i = 0 ; i < 12 ; i++){
	for(int j = 0 ; j < 6 ; j++){
	    tmp[i][j] = '.';
	}
    }
 
    for(int j = 0 ; j < 6 ; j++){
	int p = 11;
	for(int i = 11 ; i >= 0 ; i--){
	    if(field[i][j] == '.') continue;
	    tmp[p--][j] = field[i][j];
	}
    }
 
    for(int i = 0 ; i < 12 ; i++){
	for(int j = 0 ; j < 6 ; j++){
	    field[i][j] = tmp[i][j];
	}
    }
}
 
int main(){
    int Tc;
 
    cin >> Tc;
    while(Tc--){
	for(int i = 0 ; i < 12 ; i++){
	    for(int j = 0 ; j < 6 ; j++){
		cin >> field[i][j];
	    }
	}
 
	int cnt = 0;
	while(true){
	    bool flg = false;
	    memset(visited,false,sizeof(visited));
	    for(int i = 0 ; i < 12 ; i++){
		for(int j = 0 ; j < 6 ; j++){
		    if(field[i][j] == '.' || field[i][j] == 'O') continue;
		    if(visited[i][j]) continue;
		    visited[i][j] = true;
		    Bcnt = 1; CountBlock(i,j,field[i][j]);
		    if(Bcnt >= 4){
			flg = true;
			remove(i,j,field[i][j]);
		    }
		}
	    }
	    if(!flg) break;
	    cnt++; FallBlock();
	}
	cout << cnt << endl;
    }
    return 0;
}
