#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100010
const int MAX_N = 1<<17;
typedef long long ll;
 
class RMQ{
public:
    ll n,dat[2*MAX_N-1];
   
    void init(int n_){
	n = 1;
	while(n < n_){ n *= 2; }
	for(int i = 0 ; i < 2*n-1 ; i++){
	    dat[i] = 0LL;
	}
    }
 
    void update(ll k,ll a){
	k += n - 1;
	dat[k] = a;
	while(k > 0){
	    k = (k - 1) / 2;
	    dat[k] = max(dat[k*2+1],dat[k*2+2]);
	}
    }
 
    ll query(ll a,ll b,ll k,ll l,ll r){
	if(r <= a || b <= l) return 0LL;
	if(a <= l && r <= b){
	    return dat[k];
	}else{
	    ll vl = query(a,b,k*2+1,l,(l+r)/2);
	    ll vr = query(a,b,k*2+2,(l+r)/2,r);
	    return max(vl,vr);
	}
    }
};
 
int main(){
    ll N,x[MAX],sum = 0LL;
    cin >> N;
    for(int i = 0 ; i < N ; i++){
	cin >> x[i];
	sum += x[i];
    }
    RMQ rmq;
    rmq.init(N);
    for(int i = 0 ; i < N ; i++){
	ll c = rmq.query(1,x[i]+1,0,0,rmq.n);
	rmq.update(x[i],c+x[i]);
    }
    cout << sum-rmq.query(1,N+1,0,0,rmq.n) << endl;
    return 0;
}
