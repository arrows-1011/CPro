#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 401;
const int INF = -9999999;
 
int main(){
    int n,m,a,b,c,g[MAX][MAX];
    fill(g[0],g[MAX],INF);
 
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
	cin >> a >> b >> c;
	g[a][b] = c;
    }
 
    for(int k = 0 ; k < n ; k++){
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		g[i][j] = max(g[i][j],g[i][k]+g[k][j]);
	    }
	}
    }
    
    cout << g[0][n-1] << endl;
    return 0;
}
