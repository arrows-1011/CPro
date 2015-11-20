#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 100000
#define MAX_N 50
#define MAX_S 3001
typedef long long ll;
 
int main(){
    int N,M,S;
    while(cin >> N >> M >> S, N){
        ll dp[MAX_N][MAX_S] = {{}};
        dp[0][0] = 1;
        for(int i = 1 ; i <= M ; i++){
            for(int j = N*N ; j > 0 ; j--){
                for(int k = 0 ; k <= S-i ; k++){
                    dp[j][k+i] += dp[j-1][k];
                    dp[j][k+i] %= MOD;
                }
            }
        }
        cout << dp[N*N][S] << endl;
    }
    return 0;
}
