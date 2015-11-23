#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll mod = 1000000007;
 
ll p(ll x){
    if(x == 0) return 1;
    return (x*p(x-1))%mod;
}
 
int main(){
    int N,x[10001];
    map<int,int> mp;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> x[i];
	mp[x[i]]++;
    }
    sort(x,x+N);
    ll sum = 0LL,t = 0LL;
    for(int i = 0 ; i < N ; i++){
	sum += t+x[i];
	t += x[i];
    }
    cout << sum << endl;
    ll ans = 1LL;
    map<int,int>::iterator it = mp.begin();
    for(; it != mp.end() ; ++it){
	ans = (ans * p(it->second)) % mod;
    }
    cout << ans << endl;
    return 0;
}
