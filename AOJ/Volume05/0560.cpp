#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1010
 
int p[MAX][MAX][3];
int t[MAX][MAX][3];
 
int solve(int m,int a,int b,int c,int d){
    return t[c][d][m]-t[a-1][d][m]-t[c][b-1][m]+t[a-1][b-1][m];
}
 
int main(){
    int N,M,Q;
    cin >> N >> M >> Q;
    for(int i = 1 ; i <= N ; i++){
	for(int j = 1 ; j <= M ; j++){
	    char ch; cin >> ch;
	    int m = (ch == 'J' ? 0 :
		     ch == 'O' ? 1 : 2);
	    p[i][j][m]++; t[i][j][m]++;
	    for(int k = 0 ; k < 3 ; k++){
		p[i][j][k] += p[i][j-1][k];
	    }
	    for(int k = 0 ; k < 3 ; k++){
		t[i][j][k] += p[i-1][j][k];
		t[i][j][k] += p[i][j-1][k];
	    }
	}
	for(int j = 1 ; j <= M ; j++){
	    for(int k = 0 ; k < 3 ; k++){
		p[i][j][k] = t[i][j][k];
	    }
	}
    }
    int a,b,c,d;
    while(Q--){
	cin >> a >> b >> c >> d;
	cout << solve(0,a,b,c,d) << " "
	     << solve(1,a,b,c,d) << " "
	     << solve(2,a,b,c,d) << endl;
    }
    return 0;
}
