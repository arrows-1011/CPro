#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 12
 
int main(){
    int N,M,x,y;
    cin >> N >> M;
    bool con[MAX_N][MAX_N];
    memset(con,false,sizeof(con));
    for(int i = 0 ; i < M ; i++){
	cin >> x >> y; x--; y--;
	con[x][y] = con[y][x] = true;
    }
    int res = -1;
    for(int S = 0 ; S < (1<<N) ; S++){
	int s = __builtin_popcount(S);
	try{
	    for(int i = 0 ; i < N ; i++){
		for(int j = i+1 ; j < N ; j++){
		    if((S >> i & 1) && (S >> j & 1) && !con[i][j]){
			throw 0;
		    }
		}
	    }
	    res = max(res,s);
	}catch(...){}
    }
    cout << res << endl;
    return 0;
}
