#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 16;
typedef long long ll;
 
struct Point{
    int x,y;
};
 
int main(){
    int tcase,n;
    ll dp[MAX][MAX];
    Point g,ps,pg;
 
    cin >> tcase;
    while(tcase--){
	memset(dp,0,sizeof(dp));
 
	cin >> g.x >> g.y;
 
	bool m[MAX][MAX][MAX][MAX];
	memset(m,false,sizeof(m));
 
	cin >> n;
	while(n--){
	    cin >> ps.x >> ps.y >> pg.x >> pg.y;
	    m[ps.y][ps.x][pg.y][pg.x] = true;
	    m[pg.y][pg.x][ps.y][ps.x] = true;     
	}
 
	dp[0][0] = 1;
 
	for(int i = 0; i <= g.y ; i++){
	    for(int j = 0 ; j <= g.x ; j++){
		if(i && !m[i][j][i-1][j]){
		    dp[i][j] += dp[i-1][j];
		}
		if(j && !m[i][j][i][j-1]){
		    dp[i][j] += dp[i][j-1];
		}
	    }
	}
 
	if(!dp[g.y][g.x]){
	    cout << "Miserable Hokusai!" << endl;
	}
	else{
	    cout << dp[g.y][g.x] << endl;
	}
    }
    return 0;
}
