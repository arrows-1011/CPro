#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main(){
    ll N,M,K;
    while(cin >> N >> M, N){
        vector<ll> sum(N+1,0);
        for(int i = 0 ; i < N ; i++){
            cin >> K;
            sum[i+1] = (sum[i] + K) % M;
        }
        ll res = 0;
        set<ll> st = {0};
        for(int i = 1 ; i <= N ; i++){
            st.insert(sum[i]);
            res = max(res, sum[i]%M);
            auto x = st.upper_bound(sum[i]);
            if(x == st.end()) continue;
            res = max(res, (sum[i]-*x+M)%M);
        }
        cout << res << endl;
    }
    return 0;
}
