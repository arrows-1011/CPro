#include <iostream>
#include <cmath>
 
using namespace std;
 
const int MAX = 1e5;
 
int main(){
    int n,m,len;
    int dp[MAX] = {0};
 
    cin >> n >> m;
    for(int i = 1 ; i < n ; i++){
	cin >> len;
	dp[i] = dp[i-1] + len;
    }
 
    int a,ans = 0,pos = 0;
    for(int i = 0 ; i < m ; i++){
	cin >> a;
	ans += abs(dp[a+pos] - dp[pos]);
	ans %= 100000;
	pos += a;
    }
    cout << ans << endl;
 
    return 0;
}
