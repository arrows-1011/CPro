#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100002
typedef pair<int,int> P;
 
int main(){
    int N,L,in,dp[MAX]={0};
    priority_queue<P> Q;
 
    cin >> N >> L;
    for(int i = 1 ; i <= N ; i++){
	cin >> in;
	Q.push(P(in,i));
    }
    while(!Q.empty()){
	P p = Q.top(); Q.pop();
	dp[p.second] = max(dp[p.second-1],dp[p.second+1]) + (L-p.first);
    }
    int ans = 0;
    for(int i = 1 ; i <= N ; i++){
	ans = max(ans,dp[i]);
    }
    cout << ans << endl;
    return 0;
}
