#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 250
#define MAX_R 1050
#define INF 1e8
 
int G1[MAX][MAX], G2[MAX][MAX];
int dp[MAX_R][MAX];
 
int main(){
    int N, M;
 
    while(cin >> N >> M ,(N | M)){
	fill(G1[0], G1[MAX], INF);
	fill(G2[0], G2[MAX], INF);
 
	int x, y, t;
	char ch;
	for(int i = 0 ; i < M ; i++){
	    cin >> x >> y >> t >> ch;
	    x--, y--;
	    if(ch == 'L'){
		G1[x][y] = G1[y][x] = t;
	    }else{
		G2[x][y] = G2[y][x] = t;
	    }
	}
     
	for(int i = 0 ; i < N ; i++){
	    G1[i][i] = G2[i][i] = 0;
	}
     
	for(int k = 0 ; k < N ; k++){
	    for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
		    G1[i][j] = min(G1[i][j], G1[i][k]+G1[k][j]);
		    G2[i][j] = min(G2[i][j], G2[i][k]+G2[k][j]);
		}
	    }
	}
 
	int R, z[MAX_R];
	for(int i = 0 ; i < MAX_R ; i++){
	    for(int j = 0 ; j < MAX ; j++){
		dp[i][j] = INF;
	    }
	}
 
	cin >> R;
	for(int i = 0 ; i < R ; i++){
	    cin >> z[i]; z[i]--;
	}
 
	int now = z[0];
	dp[0][now] = 0;
	for(int r = 1 ; r < R ; r++){
	    int next = z[r];
	    for(int j = 0 ; j < N ; j++){
		for(int i = 0 ; i < N ; i++){
		    dp[r][j] = min(dp[r][j], dp[r-1][i] + G1[now][i] + G2[i][j] + G1[j][next]);
		}
		dp[r][j]=min(dp[r][j], dp[r-1][j] + G1[now][next]);
	    }
	    now = next; 
	}
 
	int ans = INF;
	for(int i = 0 ; i < N ; i++){
	    ans = min(ans, dp[R-1][i]);
	}
	cout << ans << endl;
    }
 
    return 0;
}
