#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1001
#define INF 1e9
#define all(x) (x).begin(),(x).end()
 
struct P{
    int a,b;
    bool operator < (const P &p)const{
	if(b != p.b){
	    return b < p.b;
	}else{
	    return a < p.a;
	}
    }
};
 
int N,dp[MAX_N][MAX_N];
vector<P> p;
 
int main(){
    cin >> N;
    p.resize(N);
    for(int i = 0 ; i < N ; i++){
	cin >> p[i].a >> p[i].b;
    }
    sort(all(p));
    fill(dp[0],dp[0]+MAX_N*MAX_N,INF);
    dp[0][0] = 0;
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < N ; j++){
	    if(dp[i][j] == INF) continue;
	    dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
	    if(dp[i][j] + p[i].a <= p[i].b){
		dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j]+p[i].a);
	    }
	}
    }
    for(int i = N ; i >= 0 ; i--){
	if(dp[N][i] != INF){
	    cout << i << endl;
	    break;
	}
    }
    return 0;
}
