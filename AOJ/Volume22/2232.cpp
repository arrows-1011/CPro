#include <iostream>
#include <cstring>
 
using namespace std;
 
#define MAX 35
 
int H,W,N;
char field[MAX][MAX];
bool flg;
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
void del(){
    bool rem[MAX][MAX];
    memset(rem,false,sizeof(rem));
    for(int y = 0 ; y < H ; y++){
	for(int x = 0 ; x < W ; x++){
	    if(field[y][x] == '.') continue;
	    int n = 0, nx = x, ny = y; 
	    char ch = field[y][x];
	    while(true){
		if(!inField(ny,nx)) break;
		if(field[ny][nx] != ch) break;
		n++; nx++;
	    }
	    if(n >= N){
		for(int j = 0 ; j < n ; j++){
		    rem[y][nx-j-1] = true;
		}
	    }
	    nx = x, ny = y, n = 0;
	    while(true){
		if(!inField(ny,nx)) break;
		if(field[ny][nx] != ch) break;
		n++; ny++;
	    }
	    if(n >= N){
		for(int j = 0 ; j < n ; j++){
		    rem[ny-j-1][x] = true;
		}
	    }
	}
    }
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    if(rem[i][j]){
		flg = true;
		field[i][j] = '.';
	    }
	}
    }
}
 
void fall(){
    char t[MAX][MAX];
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    t[i][j] = '.';
	}
    }
   
    for(int j = 0 ; j < W ; j++){
	int idx = H-1;
	for(int i = H-1 ; i >= 0 ; i--){
	    if(field[i][j] == '.') continue;
	    t[idx--][j] = field[i][j];
	}
    }
 
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    field[i][j] = t[i][j];
	}
    }
}
 
bool check(){
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    if(field[i][j] != '.') return false;
	}
    }
    return true;
}
 
bool solve(){
    if(check()) return true;
    flg = false; del(); 
    if(flg){
	fall(); 
	if(solve()) return true;
    }
    return false;
}
 
int main(){
    cin >> H >> W >> N;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	}
    }
    char tmp[MAX][MAX];
    bool ok = false;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W-1 ; j++){
	    if(field[i][j] == field[i][j+1]) continue;
	    for(int k = 0 ; k < H ; k++){
		for(int l = 0 ; l < W ; l++){
		    tmp[k][l] = field[k][l];
		}
	    }
	    swap(field[i][j],field[i][j+1]);
	    if(field[i][j] == '.' || field[i][j+1] == '.'){
		fall();
	    }
	    if(solve()){
		ok = true;
		goto end;
	    }
	    for(int k = 0 ; k < H ; k++){
		for(int l = 0 ; l < W ; l++){
		    field[k][l] = tmp[k][l];
		}
	    }
	}
    }
end:;
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
