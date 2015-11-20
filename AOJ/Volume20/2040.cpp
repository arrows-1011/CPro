#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 16
#define INF 1e9
 
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
 
int N,S,G;
int dp[1<<MAX][MAX];
char panels[MAX];
 
void solve(int s){
    priority_queue<piii,vector<piii>,greater<piii> > Q;
    Q.push(piii(pii(0,s),S));
   
    while(!Q.empty()){
	piii p = Q.top(); Q.pop();
	int cost = p.first.first, v = p.first.second;
	int bit = p.second;
 
	if(dp[bit][v] < cost) continue;
	for(int i = 0 ; i < N ; i++){
	    if(i == v) continue;
	    if(((bit >> v) & 1) == ((bit >> i) & 1)) continue;   
	    int c = abs(i-v), nS = bit;
	    if((nS >> v) & 1){
		nS -= (1<<v);
	    }else{
		nS |= (1<<v);
	    }
	    if((nS >> i) & 1){
		nS -= (1<<i);
	    }else{
		nS |= (1<<i);
	    }
	    if(dp[bit][v] + c < dp[nS][i]){
		dp[nS][i] = dp[bit][v] + c;
		Q.push(piii(pii(dp[nS][i],i),nS));
	    }
	}
	for(int i = 0 ; i < N ; i++){
	    if(i == v) continue;
	    int c = abs(i-v);
	    if(dp[bit][v] + c < dp[bit][i]){
		dp[bit][i] = dp[bit][v] + c;
		Q.push(piii(pii(dp[bit][i],i),bit));
	    }
	}
    }
}
 
int main(){
    string in;
    while(cin >> N && N){
	S = G = 0;
	for(int i = 0 ; i < (1<<MAX) ; i++){
	    for(int j = 0 ; j < MAX ; j++){
		dp[i][j] = INF;
	    }
	}
	for(int i = 0 ; i < 2 ; i++){
	    cin >> in;
	    for(int j = 0 ; j < N ; j++){
		if(i == 0){
		    panels[j] = in[j];
		    if(panels[j] == 'W'){
			S |= (1<<j);
		    }
		}else{
		    if(in[j] == 'W'){
			G |= (1<<j);
		    }
		}
	    }
	}
    
	for(int i = 0 ; i < N ; i++){
	    dp[S][i] = 0;
	    solve(i);
	}
 
	int ans = INF;
	for(int i = 0 ; i < N ; i++){
	    ans = min(ans,dp[G][i]);
	}
	cout << ans << endl;
    }
    return 0;
}
