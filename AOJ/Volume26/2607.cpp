#include <bits/stdc++.h>

using namespace std;

#define MAX 100001
typedef vector<int> Vec;
typedef vector<Vec> Vecs;

int main(){
    int N,D,X;
    cin >> N >> D >> X;
    Vecs p(D,vector<int>(N));
    for(int i = 0 ; i < D ; i++){
	for(int j = 0 ; j < N ; j++){
	    cin >> p[i][j];
	}
    }
    Vecs dp(N+1,vector<int>(MAX));
    for(int i = 0 ; i < D-1 ; i++){
	for(int j = 0 ; j < N ; j++){
	    for(int k = 0 ; k <= X ; k++){
		dp[j][k] = k;
	    }
	}
	for(int j = 0 ; j < N ; j++){
	    for(int k = 0 ; k <= X ; k++){
		if(k < p[i][j]){
		    dp[j+1][k] = dp[j][k];
		}else{
		    dp[j+1][k] = max(dp[j][k],
				     dp[j+1][k-p[i][j]]+p[i+1][j]);
		}
	    }
	}
	int maxi = 0;
	for(int j = 0 ; j <= X ; j++){
	    maxi = max(maxi,dp[N][j]);
	}
	X = max(X,maxi);
    }
    cout << X << endl;
    return 0;
}
