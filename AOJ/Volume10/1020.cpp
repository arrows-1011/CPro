#include <bits/stdc++.h>
 
using namespace std;
 
bool inField(int x,int y){
    return (0 <= x && x < 3 && 0 <= y && y < 3);
}
 
int main(){
    int n;
    while(cin >> n, n){
        char s,t,b;
        double dp[20][20] = {{0}};
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        cin >> s >> t >> b;
        int S = s-'A',T = t-'A',B = b-'A';
        dp[n][S] = 1;
        for(int i = n ; i > 0 ; i--){
            for(int j = 0 ; j < 9 ; j++){
                int x = j%3, y = j/3;
                for(int k = 0 ; k < 4 ; k++){
                    int nx = x + dx[k],ny = y + dy[k];
                    int nj = ny*3+nx;
                    if(!inField(nx,ny) || nj == B){
                        dp[i-1][j] += dp[i][j]/4;
                    }else{
                        dp[i-1][nj] += dp[i][j]/4;
                    }
                }
            }
        }
        printf("%.12f\n",dp[0][T]);
    }
    return 0;
}
