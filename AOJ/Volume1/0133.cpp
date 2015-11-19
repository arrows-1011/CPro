#include <iostream>
 
using namespace std;
 
#define rep(i,n) for(int i = 0 ; i < n ; i++)
 
int main(){
    char a[8][8][4];
 
    rep(i,8){
	rep(j,8){
	    cin >> a[i][j][0];
	}
    }
 
    rep(k,3){
	cout << (k+1)*90 << endl;
	rep(i,8){
	    rep(j,8){
		cout << a[7-j][i][k];
		a[i][j][k+1] = a[7-j][i][k];
	    }
	    cout << endl;
	}
    }
    return 0;
}
