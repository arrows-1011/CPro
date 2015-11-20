#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
const int MAX_N = 1<<17;
typedef pair<int,int> pii;
 
class RMQ{
public:
    int n;
    pii dat[2*MAX_N-1];
 
    void init(int n_){
	n = 1;
	while(n < n_){ n *= 2; }
	for(int i = 0 ; i < 2*n-1 ; i++){
	    dat[i] = pii(-INF,-INF);
	}
	for(int i = 0 ; i < n_ ; i++){
	    update(i,0);
	}
    }
 
    void update(int k,int a){
	int tk = k;
	k += n - 1;
	dat[k] = pii(a,-tk);
	while(k > 0){
	    k = (k - 1) / 2;
	    dat[k] = max(dat[k*2+1],dat[k*2+2]);
	}
    }
 
    pii query(int a,int b,int k,int l,int r){
	if(r <= a || b <= l){ return pii(-INF,-INF); }
	if(a <= l && r <= b){
	    return dat[k];
	}else{
	    pii vl = query(a,b,k*2+1,l,(l+r)/2);
	    pii vr = query(a,b,k*2+2,(l+r)/2,r);
	    return max(vl,vr);
	}
    }
};
 
int main(){
    int N,R,L;
    RMQ rmq;
    cin >> N >> R >> L;
    rmq.init(N);
    int d,t,x,pt = 0;
    vector<int> point(N,0);
    for(int i = 0 ; i < R ; i++){
	cin >> d >> t >> x; d--;
	point[-rmq.query(0,N,0,0,rmq.n).second] += t - pt;
	rmq.update(d,x+rmq.dat[d+rmq.n-1].first);
	pt = t;
    }
    point[-rmq.query(0,N,0,0,rmq.n).second] += L - pt;
    int res = -1, max = -INF;
    for(int i = 0 ; i < N ; i++){
	if(max < point[i]){
	    max = point[i];
	    res = i+1;
	}
    }
    cout << res << endl;
    return 0;
}
