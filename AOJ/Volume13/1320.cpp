#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 15
#define INF 1e9
 
int N;
int G[MAX][MAX],bit;
int len[MAX];
int dp[1<<MAX][MAX];
string s[MAX];
 
int calc(int a,int b){
    string s1 = s[a],s2 = s[b];
    int l1 = len[a],l2 = len[b];
 
    if(s2.find(s1) != string::npos &&
       s1.find(s2) == string::npos){
	bit |= (1<<a);
	return 0;
    }else if(s1.find(s2) != string::npos &&
	     s2.find(s1) == string::npos){
	bit |= (1<<b);
	return 0;
    }
   
    for(int i = min(l1,l2) ; i >= 0 ; i--){
	string subs1 = s1.substr(l1-i,i);
	string subs2 = s2.substr(0,i);
	if(subs1 == subs2){
	    return subs1.size();
	}
    }
    return 0;
}
 
int solve(int S,int v){
    if(S == (1<<N)-1) return 0;
    if(dp[S][v] != -1) return dp[S][v];
    int res = INF;
    for(int i = 0 ; i < N ; i++){
	if((S >> i) & 1) continue;
	res = min(res,solve(S|(1<<i),i)+len[i]-G[v][i]);
    }
    return dp[S][v] = res;
}
 
int main(){
    while(cin >> N,N){
	bit = 0;
	memset(dp,-1,sizeof(dp));
	fill(G[0],G[0]+MAX*MAX,INF);
	for(int i = 0 ; i < N ; i++){
	    cin >> s[i];
	    len[i] = s[i].size();
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j) continue;
		G[i][j] = calc(i,j);
	    }
	}
	int res = INF;
	for(int i = 0 ; i < N ; i++){
	    if((bit >> i) & 1) continue;
	    res = min(res,solve(bit|(1<<i),i)+len[i]);
	}
	cout << res << endl;
    }
    return 0;
}
