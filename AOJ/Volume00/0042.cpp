#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 1001
 
int dp[MAX][MAX],t,w,m;
int Val[MAX],Wei[MAX];
 
void judge(){
    for(int i = 1 ; i <= m ; i++){
        for(int j = 1 ; j <= w ; j++){
            int k = j - Wei[i];
            if(k < 0){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][k]+Val[i]);
            }
        }
    }
    int ans_W = 0,ans_C;
    for(int i = 1 ; i <= w ; i++){
        ans_W = max(ans_W,dp[m][i]);
    }
    for(int i = w ; i >= 1 ; i--){
        if(ans_W==dp[m][i]) ans_C = i;
    }
    cout << ans_W << endl;
    cout << ans_C << endl;
}
 
void print(){
    cout << "Case " << t++ << ":" << endl;
}
 
int main(){
    char c;   
    t = 1;
    while(cin >> w,w){
        cin >> m;
         
        fill(dp[0],dp[MAX-1],0);
        Wei[0] = Val[0] = 0;
         
        print();
        for(int j = 1 ; j <= m ; j++) cin >> Val[j] >> c >> Wei[j];
        judge();
    }
    return 0;
}
