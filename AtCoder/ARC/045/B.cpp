#include <bits/stdc++.h>
 
using namespace std;
 
const int MAX_N = 1<<19;
 
int n,dat[2*MAX_N-1];
  
void init(int n_){
    n = 1;
    while(n < n_) n *= 2;
    for(int i = 0 ; i < 2*n-1 ; i++){
        dat[i] = INT_MAX;
    }
}
 
void init(int n_,vector<int> &v){
    int N = v.size();
    init(n_);
    for(int i = (N-1) + (n-1) ; i >= 0 ; i--){
        if(n-1 <= i) dat[i] = v[i-(n-1)];
        else dat[i] = min(dat[i*2+1], dat[i*2+2]);
    }
}
  
void update(int k,int a){
    k += n - 1;
    dat[k] = a;
    while(k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k*2+1],dat[k*2+2]);
    }
}
 
int query(int a,int b,int k,int l,int r){
    if(r <= a || b <= l) return INT_MAX;
    if(a <= l && r <= b){
        return dat[k];
    }else{
        int vl = query(a,b,k*2+1,l,(l+r)/2);
        int vr = query(a,b,k*2+2,(l+r)/2,r);
        return min(vl,vr);
    }
}
 
int main(){
    int N,M;
    cin >> N >> M;
    vector<int> s(M),t(M);
    vector<int> dp(N+1, 0);
    for(int i = 0 ; i < M ; i++){
        cin >> s[i] >> t[i]; s[i]--; t[i]--;
        dp[s[i]]++; dp[t[i]+1]--;
    }
    for(int i = 1 ; i < N ; i++){
        dp[i] += dp[i-1];
    }
    init(N, dp);
    vector<int> res;
    for(int i = 0 ; i < M ; i++){
        int x = query(s[i],t[i]+1,0,0,n);
        if(x != 1){
            res.push_back(i+1);
        }
    }
    cout << res.size() << endl;
    for(int i = 0 ; i < (int)res.size() ; i++){
        cout << res[i] << endl;
    }
    return 0;
}
