#include <bits/stdc++.h>
  
using namespace std;
  
#define EPS 1e-8
#define equal(a,b) (fabs(a-b) < EPS)
#define lt(a,b) (a-b < -EPS)
#define le(a,b) (lt(a,b) || equal(a,b))
#define MAX_N 86401
#define MAX_L 1000000
#define END 86400
  
struct P{
    double s,t,u;
    P(){}
    P(double s,double t,double u) : s(s),t(t),u(u) {}
    bool operator < (const P &p)const{
	return s < p.s;
    }
};
 
int main(){
    int N;
    double L;
    P p[MAX_N];
    while(cin >> N >> L,N){
	for(int i = 0 ; i < N ; i++){
	    cin >> p[i].s >> p[i].t >> p[i].u;
	}
	sort(p,p+N);
	double l = 0, r = MAX_L;
	for(int i = 0 ; i < 150 ; i++){
	    double mid = (l + r) / 2.0;
	    bool ok = true;
	    double rem[2]; rem[0] = L;
	    for(int j = 0 ; j < 2 ; j++){
		double prev = 0;
		for(int k = 0 ; k < N ; k++){
		    rem[j] = min(L,rem[j]+mid*(p[k].s-prev));
		    double d = p[k].t-p[k].s;
		    rem[j] = min(L,rem[j]+d*(mid-p[k].u));
		    if(le(rem[j],0)){ ok = false; break; }
		    prev = p[k].t;
		}
		rem[j] = min(L,rem[j]+mid*(END-prev));
		if(j == 0){ rem[1] = rem[0]; }
		else if(lt(rem[1],rem[0])){
		    ok = false;
		}
		if(!ok){ break; }
	    }
	    if(ok){ r = mid; }else{ l = mid; }
	}
	printf("%.8f\n",r);
    }
    return 0;
}
