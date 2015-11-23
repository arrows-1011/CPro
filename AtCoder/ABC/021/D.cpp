#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_P 300000
#define MOD 1000000007
typedef long long ll;
 
ll fact[MAX_P];
 
ll extgcd(ll a,ll b,ll &x,ll &y){
    ll d = a;
    if(b != 0){
	d = extgcd(b,a%b,y,x);
	y -= (a / b) * x;
    }else{
	x = 1; y = 0;
    }
    return d;
}
 
ll mod_inverse(ll a,ll m){
    ll x,y;
    extgcd(a,m,x,y);
    return (m + x % m) % m;
}
 
ll mod_fact(ll n,ll p,ll &e){
    e = 0;
    if(n == 0) return 1;
    ll res = mod_fact(n/p,p,e);
    e += n/p;
    if(n / p % 2 != 0) return res * (p - fact[n % p]) % p;
    return res * fact[n % p] % p;
}
 
ll mod_comb(ll n,ll k,ll p){
    if(n < 0 || k < 0 || n < k) return 0;
    ll e1,e2,e3;
    ll a1 = mod_fact(n,p,e1),a2 = mod_fact(k,p,e2),a3 = mod_fact(n-k,p,e3);
    if(e1 > e2 + e3) return 0;
    return a1 * mod_inverse(a2 * a3 % p,p) % p;
}
 
int main(){
    ll N,K;
    cin >> N >> K;
    fact[0] = 1;
    for(int i = 1 ; i <= N+K ; i++){
	fact[i] += i*fact[i-1];
	fact[i] %= MOD;
    }
    cout << mod_comb(N+K-1,K,MOD) << endl;
    return 0;
}
