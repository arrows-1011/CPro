#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 100000
#define MAX_S 30
 
double dp[MAX_N+1][MAX_S+1];
 
int main(){
    double P[MAX_N],power[MAX_S];
    dp[0][0] = 1; P[0] = 1;
    power[0] = 1;
    for(int i = 1 ; i < MAX_S ; i++){
        power[i] = power[i-1]/2;
    }
    for(int i = 0 ; i < MAX_N-1 ; i++){
        for(int j = 0 ; j < MAX_S ; j++){
            if(dp[i][j] == 0) continue;
            dp[i+1][j+1] += dp[i][j]*power[j];
            dp[i+1][0] += dp[i][j]*(1-power[j]);
        }
        double res = 0;
        for(int j = 0 ; j < MAX_S ; j++){
            res += dp[i+1][j]*power[j];
        }
        P[i+1] = res + P[i];
    }
    int n;
    while(cin >> n,n){
        printf("%.10f\n",P[n-1]);
    }
    return 0;
}
