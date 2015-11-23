#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000010
#define MOD 10007
 
int dp[MAX];
 
int main(){
    int N;
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3 ; i < MAX ; i++){
	dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    cin >> N;
    cout << dp[N-1] << endl;
    return 0;
}
