#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 45
#define INF 1e9
 
int N,p[MAX],t[MAX];
int dp[MAX][4];
bool used[MAX];
 
void init(){
    p[0] = t[0] = 0;
    fill(dp[0],dp[0]+MAX*4,INF);
    memset(used,false,sizeof(used));
}
 
int d(int idx,bool v){
    if(v){
	return p[idx]+p[idx+1];
    }else{
	return abs(p[idx]-p[idx+1]);
    }
}
 
int solve(int idx,int cap){
    used[idx] = true;
    if(idx == N){
	return dp[idx][cap] = p[idx];
    }
    int &res = dp[idx][cap],dt = t[idx+1]-t[idx];
    if(res != INF) return res;
    if(p[idx]*(cap+1)+p[idx+1] <= dt){
	res = min(res,solve(idx+1,1) + d(idx,1));
    }
    if(cap < 3 && d(idx,0)*(cap+1) <= dt){
	res = min(res,solve(idx+1,cap+1) + d(idx,0));
    }
    return res;
}
 
int main(){
    while(cin >> N, N){
	init();
	for(int i = 1 ; i <= N ; i++){
	    cin >> p[i] >> t[i];
	}
	int ans = solve(0,0);
	if(ans != INF){
	    cout << "OK " << ans << endl;
	}else{
	    cout << "NG " << find(used+1,used+N,false)-used << endl;
	}
    }
    return 0;
}
