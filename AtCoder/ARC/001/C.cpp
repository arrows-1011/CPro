#include <bits/stdc++.h>
 
using namespace std;
 
bool flg;
const int dx[4] = {-1,1,1,-1};
const int dy[4] = {-1,-1,1,1};
 
bool inField(int x,int y){
    return (0 <= x && x < 8 && 0 <= y && y < 8);
}
 
void putQ(int r,int c,bool can[8][8]){
    for(int i = 0 ; i < 8 ; i++){
	can[r][i] = can[i][c] = false;
    }
    for(int i = 0 ; i < 4 ; i++){
	int x = c,y = r;
	while(inField(x,y)){
	    can[y][x] = false;
	    x += dx[i]; y += dy[i];
	}
    }
}
  
void print(char field[8][8]){
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    cout << field[i][j];
	}
	cout << endl;
    }
}
  
void copy(bool a[8][8],bool b[8][8]){
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    a[i][j] = b[i][j];
	}
    }
}
 
bool check(char field[8][8]){
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    if(field[i][j] != 'Q') continue;
	    for(int k = 0 ; k < 8 ; k++){
		if(i == k || j == k) continue;
		if(field[i][k] == 'Q' || field[k][j] == 'Q'){
		    return true;
		}
	    }
	    for(int k = 0 ; k < 4 ; k++){
		int x = j + dx[k],y = i + dy[k];
		while(inField(x,y)){
		    if(field[y][x] == 'Q') return true;
		    x += dx[k]; y += dy[k];
		}
	    }
	}
    }
    return false;
}
  
void solve(int now,int S,bool can[8][8],char field[8][8]){
    if(now == 8){
	print(field);
	flg = true;
	return;
    }
    if((S >> now) & 1){
	solve(now+1,S,can,field);
    }else{
	bool tmp[8][8];
	for(int i = 0 ; i < 8 ; i++){
	    if(can[now][i]){
		copy(tmp,can);
		field[now][i] = 'Q';
		putQ(now,i,can);
		solve(now+1,S,can,field);
		if(flg) return;
		copy(can,tmp);
		field[now][i] = '.';
	    }
	}
    }
}
 
int main(){
    int S = 0;
    bool can[8][8];
    char field[8][8];
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    cin >> field[i][j];
	    can[i][j] = true;
	}
    }
    for(int i = 0 ; i < 8 ; i++){
	for(int j = 0 ; j < 8 ; j++){
	    if(field[i][j] == 'Q'){
		S |= (1<<i);
		putQ(i,j,can);
	    }
	}
    }
    if(check(field)){
	cout << "No Answer" << endl;
    }else{
	solve(0,S,can,field);
	if(!flg){
	    cout << "No Answer" << endl;
	}
    }
    return 0;
}
