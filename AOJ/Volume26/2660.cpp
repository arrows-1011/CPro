#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 310
#define INF LLONG_MAX/4
typedef long long ll;
 
ll N,a[MAX],s[MAX];
ll memo[MAX][MAX];
 
int getSize(ll v){
    int cnt = 0;
    while(v > 0){
        v /= 10; cnt++;
    }
    return cnt;
}
 
ll calc(ll X,ll Y){
    ll res = 0LL,c = 0;
    int size = max(getSize(X),getSize(Y));
    for(int i = 0 ; i < size ; i++){
        ll x = X%10,y = Y%10;
        c = (x + y + c) / 10;
        res += x*y+c;
        X /= 10; Y /= 10;
    }
    return res;
}
 
ll solve(int L,int R){
    if(L+1 == R) return 0;
    ll &res = memo[L][R];
    if(res != INF) return res;
    for(int i = L+1 ; i < R ; i++){
        ll cost = calc(s[i]-s[L],s[R]-s[i]);
        res = min(res,solve(L,i)+solve(i,R)+cost);
    }
    return res;
}
 
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> a[i];
        s[i+1] = a[i] + s[i];
    }
    fill(memo[0],memo[0]+MAX*MAX,INF);
    cout << solve(0,N) << endl;
    return 0;
}
