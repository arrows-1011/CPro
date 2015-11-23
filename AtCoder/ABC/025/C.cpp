#include <bits/stdc++.h>
 
using namespace std;
 
#define F first
#define S second
typedef pair<int,int> pii;
 
int b[2][3],c[3][2];
 
pii getPoint(vector<string> &board){
    pii p = pii(0,0);
    for(int i = 0 ; i < 2 ; i++){
	for(int j = 0 ; j < 3 ; j++){
	    if(board[i][j] == board[i+1][j]){
		p.F += b[i][j];
	    }else{
		p.S += b[i][j];
	    }
	}
    }
    for(int i = 0 ; i < 3 ; i++){
	for(int j = 0 ; j < 2 ; j++){
	    if(board[i][j] == board[i][j+1]){
		p.F += c[i][j];
	    }else{
		p.S += c[i][j];
	    }
	}
    }
    return p;
}
 
map<vector<string>,pii> memo;
 
pii solve(int step,int player,vector<string> board){
    if(memo.find(board) != memo.end()){
	return memo[board];
    }
    if(step == 9){
	return memo[board] = getPoint(board);
    }
    pii p = pii(-1,-1);
    for(int i = 0 ; i < 3 ; i++){
	for(int j = 0 ; j < 3 ; j++){
	    if(board[i][j] != '.') continue;
	    board[i][j] = (player == 0 ? 'o' : 'x');
	    pii np = solve(step+1,1-player,board);
	    board[i][j] = '.';
	    if(player == 0){
		if(np.first > p.first){
		    p = np;
		}
	    }else{
		if(np.second > p.second){
		    p = np;
		}
	    }
	}
    }
    return memo[board] = p;
}
 
int main(){
    for(int i = 0 ; i < 2 ; i++){
	for(int j = 0 ; j < 3 ; j++){
	    cin >> b[i][j];
	}
    }
    for(int i = 0 ; i < 3 ; i++){
	for(int j = 0 ; j < 2 ; j++){
	    cin >> c[i][j];
	}
    }
    pii p = solve(0,0,vector<string>(3,string(3,'.')));
    cout << p.F << endl << p.S << endl;
    return 0;
}
