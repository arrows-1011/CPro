#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
  
using namespace std;
  
#define MAX 15
#define INF 1e9
  
int N;
int path[1<<MAX][MAX];
double dp[1<<MAX][MAX];
double _time,d[MAX],B[MAX];
int n[MAX];
vector<int> ans;
  
double V(double w){
    return 2000. / (70. + w);
}
  
double dist(int a,int b){
    return abs(d[a]-d[b]);
}
  
double solve(int S,int prev,double b){
    if(N == __builtin_popcount(S)) return dp[S][prev] = 0.0;
    if(dp[S][prev] >= 0) return dp[S][prev];
    double res = INF;
    for(int i = 0 ; i < N ; i++){
	if(S >> i & 1) continue;
	double next = solve(S|(1<<i),i,b+B[i]) + dist(prev,i)/V(b);
	if(next < res){
	    res = next;
	    path[S][prev] = i;
	}
    }
    return dp[S][prev] = res;
}
  
int main(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> n[i] >> d[i] >> B[i];
	B[i] *= 20;
    }
    _time = INF;
    for(int i = 0 ; i < 1<<N ; i++){
	for(int j = 0 ; j < N ; j++){
	    dp[i][j] = -1;
	}
    }
    for(int i = 0 ; i < N ; i++){
	double now = solve(1<<i,i,B[i]);
	if(now < _time){
	    _time = now;
	    path[0][0] = i;
	}
    }
    int S = 0, p = 0;
    while(true){
	if(N == __builtin_popcount(S)) break;
	ans.push_back(n[path[S][p]]);
	int T = S;
	S |= 1<<path[S][p];
	p = path[T][p];
    }
    for(int i = 0 ; i < N ; i++){
	if(i == N-1){
	    cout << ans[i] << endl;
	}else{
	    cout << ans[i] << " ";
	}
    }
    return 0;
}
