#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 3001
  
int N, S, T, a[MAX], b[MAX];
int dp[MAX][MAX], ans;
  
void solve(){
    for(int i = 1 ; i <= N ; i++){
	for(int j = 1 ; j <= T ; j++){
	    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);;
	    int k = j - b[i];
	    if(k >= 0 && !(j-b[i] < S && S < j)){
		dp[i][j] = max(dp[i][j], dp[i-1][k] + a[i]);
	    }
	}
    }
    ans = -1;
    for(int i = 1 ; i <= T ; i++){
	ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
}
  
int main(){
    cin >> N >> T >> S;
    for(int i = 1 ; i <= N ; i++){
	cin >> a[i] >> b[i];
    }
    solve();
    return 0;
}
