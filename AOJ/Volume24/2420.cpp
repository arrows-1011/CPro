#include <iostream>

using namespace std;

#define MAX 55
#define MINF -(1e8)

int N,M,a[MAX],b[MAX],c[MAX];
int memo[MAX][MAX][MAX];

int solve(int n,int l1,int m){
    if(n == N) return 0;
    int &res = memo[n][l1][m];
    if(res != MINF) return res;
    for(int i = 0 ; i <= min(8,m) ; i++){
        for(int j = 0 ; j <= i ; j++){
            for(int k = 0 ; k <= min(l1,8-j) ; k++){
                int cost = (j+k == 0 ? c[n] : a[n]*j+b[n]*k);
                res = max(res,solve(n+1,i,m-i)+cost);    
            }
        }
    }
    return res;
}

int main(){
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    fill(&memo[0][0][0],&memo[MAX-1][MAX-1][MAX-1],MINF);
    cout << solve(0,0,M) << endl;
    return 0;
}
