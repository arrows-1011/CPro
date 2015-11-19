#include <iostream>
#include <cstring>
 
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)

int puzzle[9][9];
 
void field(int x,int &to,int &from){
    if(0 <= x && x < 3){
	to = 0;
	from = 3;
    }else if(3 <= x && x < 6){
	to = 3;
	from = 6;
    }else{
	to = 6;
	from = 9;
    }
}
 
bool check1(int x,int y){
    for(int i = x-1 ; i >= 0 ; i--){
	if(puzzle[x][y] == puzzle[i][y]) return false;
    }
    for(int i = x+1 ; i < 9 ; i++){
	if(puzzle[x][y] == puzzle[i][y]) return false;
    }
    return true;
}
 
bool check2(int x,int y){
    for(int i = y-1 ; i >= 0 ; i--){
	if(puzzle[x][y] == puzzle[x][i]) return false;
    }
    for(int i = y+1 ; i < 9 ; i++){
	if(puzzle[x][y] == puzzle[x][i]) return false;
    }
    return true;
}
 
bool check3(int x,int y){
    int sx,tx,sy,ty;
 
    field(x,sx,tx);
    field(y,sy,ty);
 
    for(int i = sx ; i < tx ; i++){
	for(int j = sy ; j < ty ; j++){  
	    if(x == i && y == j) continue;
	    if(puzzle[x][y] == puzzle[i][j]) return false;
	}
    }
    return true;
}
 
int main(){
    int T;
 
    cin >> T;
    rep(t,T){
	if(t) cout << endl;
	rep(i,9){
	    rep(j,9){
		cin >> puzzle[i][j];
	    }
	}
 	char ch[9][9];
	rep(i,9){
	    rep(j,9){
		ch[i][j] = ' ';
	    }
	}
 	rep(i,9){
	    rep(j,9){
		if(check1(i,j) && check2(i,j) && check3(i,j)) continue;
		ch[i][j] = '*';
	    }
	}
 	rep(i,9){
	    rep(j,9){
		cout << ch[i][j] << puzzle[i][j];
	    }
	    cout << endl;
	}
    }
    return 0;
}
