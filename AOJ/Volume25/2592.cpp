#include <bits/stdc++.h>

using namespace std;

#define INF (1LL<<45)
typedef vector<double> Vec;

int N;
Vec vw,pf,vf,th;

double f(double W,double pw){
    double res = 0;
    for(int i = 0 ; i < N ; i++){
	double Fi = max(0.0,(th[i]-W*vw[i])/vf[i]);
	res += Fi*pf[i];
    }
    res += W*pw;
    return res;
}

void init(){
    vw.clear(); vw.resize(N);
    pf.clear(); pf.resize(N);
    vf.clear(); vf.resize(N);
    th.clear(); th.resize(N);
}

int main(){
    double pw;
    while(scanf("%d %lf",&N,&pw), N){
	init();
	for(int i = 0 ; i < N ; i++){
	    scanf("%lf %lf %lf %lf",&vw[i],&pf[i],&vf[i],&th[i]);
	}
	double L = 0, R = INF;
	for(int i = 0 ; i < 150 ; i++){
	    double l = (L*2 + R) / 3;
	    double r = (L + R*2) / 3;
	    if(f(l,pw) > f(r,pw)){
		L = l;
	    }else{
		R = r;
	    }
	}
	printf("%.12f\n",f((L+R)/2,pw));
    }
    return 0;
}
