#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100010
typedef long long ll;
 
int main(){
    ll N,M,P[MAX],A[MAX],B[MAX],C[MAX];
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
	cin >> P[i]; P[i]--;
    }
    for(int i = 0 ; i < N-1 ; i++){
	cin >> A[i] >> B[i] >> C[i];
    }
    int dp[MAX] = {0};
    for(int i = 0 ; i < M-1 ; i++){
	ll arr[2] = {P[i],P[i+1]};
	if(P[i] > P[i+1]){ swap(arr[0],arr[1]); }
	dp[arr[0]]++; dp[arr[1]]--;
    }
    for(int i = 1 ; i < N ; i++){
	dp[i] += dp[i-1];
    }
    ll res = 0LL;
    for(int i = 0 ; i < N ; i++){
	res += min(A[i]*dp[i],B[i]*dp[i]+C[i]);
    }
    cout << res << endl;
    return 0;
}
