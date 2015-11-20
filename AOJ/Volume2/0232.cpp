#include <bits/stdc++.h>
 
using namespace std;

#define MAX 51
#define MAX_M 5001
typedef pair<int,int> pii;
 
int main(){
    int X,Y,Z,N,E,A;
    while(cin >> X >> Y >> Z, X){
        pii M[MAX];
        vector<int> V(X);
        for(int i = 0 ; i < X ; i++){
            cin >> V[i];
        }
        for(int i = 0 ; i < MAX ; i++){
            M[i] = pii(-1,-1);
        }
        for(int i = 0 ; i < Z ; i++){
            cin >> N >> E >> A;
            M[N] = pii(E,A);
        }
        double dp[MAX][MAX_M] = {{0}};
        dp[0][0] = 1;
        for(int i = 0 ; i < Y ; i++){
            for(int j = 0 ; j < MAX_M ; j++){
                if(dp[i][j] == 0) continue;
                for(int k = 0 ; k < X ; k++){
                    int next = min(i+V[k], Y);
                    int v = M[next].first;
                    int v2 = M[next].second;
                    if(v == -1){
                        dp[next][j] += dp[i][j]/X;
                    }else if(v == 2){
                        dp[next][min(j+v2,MAX_M-1)] += dp[i][j]/X;
                    }else if(v == 3){
                        dp[next][max(j-v2,0)] += dp[i][j]/X;
                    }else{
                        next = min(next+v2,Y);
                        dp[next][j] += dp[i][j]/X;
                    }
                }
            }
        }
        double res = 0;
        for(int i = 0 ; i < MAX_M ; i++){
            res += i*dp[Y][i];
        }
        cout << (int)res << endl;
    }
    return 0;
}
