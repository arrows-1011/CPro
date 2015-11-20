#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
typedef long long ll;
 
string A,B,C;
 
void reverse(){
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    reverse(C.begin(),C.end());
}
 
int main(){
    while(cin >> A, A != "0"){
	cin >> B >> C;
	reverse();
	int size = A.size();
	ll dp[51][2];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int p = 0 ; p < size ; p++){
	    for(int i = 0 ; i < 10 ; i++){
		if(A[p] != '?' && (A[p]-'0') != i){
		    continue;
		}
		if(p == size-1 && i == 0) continue;
		for(int j = 0 ; j < 10 ; j++){
		    if(B[p] != '?' && (B[p]-'0') != j){
			continue;
		    }
		    if(p == size-1 && j == 0) continue;
		    for(int k = 0 ; k < 2 ; k++){
			int l = (i + j + k) % 10;
			int nk = (i + j + k >= 10);
			if(C[p] != '?' && (C[p]-'0') != l){
			    continue;
			}
			dp[p+1][nk] += dp[p][k];
			dp[p+1][nk] %= MOD;
		    }
		}
	    }
	}
	cout << dp[size][0] << endl;
    }
    return 0;
}
