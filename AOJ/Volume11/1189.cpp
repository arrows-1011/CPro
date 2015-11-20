#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1200
#define LIMIT 1000100
typedef pair<int,int> pii;
 
int M,N;
int caves[MAX][MAX];
int dp[MAX][MAX];
map<int,pii> mp;
bool prime[LIMIT];
 
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
 
void makePrime(){
    fill(prime,prime+LIMIT,true);
    prime[0] = prime[1] = false;
    for(int i = 2 ; i*i < LIMIT ; i++){
	if(prime[i]){
	    for(int j = i*2 ; j < LIMIT ; j+=i){
		prime[j] = false;
	    }
	}
    }
}
 
void makeCaves(){
    int x = 600,y = 600,dir = 0;
    int num = 1,cnt = 1;
    while(true){
	if(cnt == LIMIT) break;
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < num ; j++){
		mp[cnt] = pii(y,x);
		caves[y][x] = cnt++;
		if(cnt == LIMIT){
		    return;
		}
		x += dx[dir];
		y += dy[dir];
	    }
	    dir = (dir+1)%4;   
	}
	num++;
    }
}
 
void solve(int sx,int sy){
    dp[sy][sx] = prime[caves[sy][sx]];
    for(int i = 0 ; i < MAX-1 ; i++){
	for(int j = 1 ; j < MAX-1 ; j++){
	    if(dp[i][j] >= 0 && caves[i][j] <= M){
		if(caves[i+1][j-1] <= M){
		    dp[i+1][j-1] = max(dp[i+1][j-1],dp[i][j]+prime[caves[i+1][j-1]]); 
		}
		if(caves[i+1][j] <= M){
		    dp[i+1][j] = max(dp[i+1][j],dp[i][j]+prime[caves[i+1][j]]); 
		}
		if(caves[i+1][j+1] <= M){
		    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+prime[caves[i+1][j+1]]); 
		}
	    }
	}
    }
    int res = 0, num = 0;
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX ; j++){
	    if(caves[i][j] <= M && prime[caves[i][j]]){
		if(res < dp[i][j]){
		    res = dp[i][j];
		    num = caves[i][j];
		}else if(res == dp[i][j]){
		    if(num < caves[i][j]){
			num = caves[i][j];
		    }
		}
	    }
	}
    }
    cout << res << " " << num << endl;
}
 
int main(){
    makeCaves();
    makePrime();
    while(cin >> M >> N, M){
	pii src = mp[N];
	memset(dp,-1,sizeof(dp));
	solve(src.second,src.first);
    }
    return 0;
}
