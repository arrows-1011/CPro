#include <iostream>
#include <cmath>
 
using namespace std;
 
#define rep(i,b,n) for(int i = b ; i < n ; i++)
const int MAX = 500;
 
int main(){
    int H,W;
 
    while(cin >> H >> W , H | W){
	string s[MAX];
	int field[MAX][MAX];
 
	rep(i,0,H){
	    cin >> s[i];
	    rep(j,0,W){
 
		if(s[i][j] == '*') field[i][j] = 0;
		else{
		    if(j > 0) field[i][j] = field[i][j-1] + 1;
		    else field[i][j] = 1;
		}
 
	    }
	}
 
	int res = 0;
 
	rep(i,0,W){
	    rep(j,0,H){
		int width = 1e9;
		rep(k,j,H){
		    width = min(width,field[k][i]);
		    res = max(res,(k-j+1)*width);
		}
	    }
	}
	cout << res << endl;
    }
    return 0;
}
