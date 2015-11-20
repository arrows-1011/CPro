#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_W 10000
#define INF LLONG_MAX/4
typedef long long ll;
 
ll dp[MAX_W+1];
 
int main(){
    ll M,N,E;
    int C;
    cin >> M >> N;
    vector<ll> P(M);
    for(ll i = 0 ; i < M ; i++){
        cin >> P[i];
    }
    sort(P.begin(),P.end(),greater<ll>());
    fill(dp,dp+MAX_W+1,INF);
    dp[0] = 0;
    for(ll i = 0 ; i < N ; i++){
        cin >> C >> E;
        for(int j = MAX_W ; j >= 0 ; j--){
            dp[j] = min(dp[j],dp[max(0,j-C)]+E);
        }
    }
    ll res = 0,sum = 0;
    for(int i = 0 ; i < M ; i++){
        sum += P[i];
        res = max(res,sum-dp[i+1]);
    }
    cout << res << endl;
    return 0;
}
