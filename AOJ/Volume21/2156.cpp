#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100
#define MAX_H 100000
#define INF (1<<29)
typedef long long ll;
 
int main(){
    ll N,M;
    string in;
    while(cin >> N, N){
        ll MHP = 0;
        vector<ll> HP(N);
        for(ll i = 0 ; i < N ; i++){
            cin >> HP[i];
            MHP = max(MHP,HP[i]);
        }
        cin >> M;
        vector<ll> MP(M),t(M),d(M);
        for(ll i = 0 ; i < M ; i++){
            cin >> in >> MP[i] >> in >> d[i];
            t[i] = (in == "All");
        }
        ll dp[2][MAX_H+1];
        fill(dp[0],dp[0]+2*(MAX_H+1),INF);
        dp[0][0] = dp[1][0] = 0;
        for(ll i = 0 ; i < M ; i++){
            for(ll j = 0 ; j <= MHP ; j++){
                ll nt = t[i],nhp = min(MHP,j+d[i]);
                dp[nt][nhp] = min(dp[nt][nhp],dp[nt][j]+MP[i]);
            }
        }
        for(ll i = MHP ; i > 0 ; i--){
            dp[0][i-1] = min(dp[0][i-1],dp[0][i]);
            dp[1][i-1] = min(dp[1][i-1],dp[1][i]);
        }
        ll res = INF;
        for(ll i = 0 ; i <= MHP ; i++){
            ll mp = dp[1][i],mp2 = 0;
            if(mp == INF) continue;
            for(ll j = 0 ; j < N ; j++){
                ll rest = max(HP[j]-i,0LL);
                if(rest == 0) continue;
                mp2 += dp[0][rest];
            }
            res = min(res,mp+mp2);
        }
        cout << res << endl;
    }
    return 0;
}
