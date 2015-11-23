#include <bits/stdc++.h>
 
using namespace std;
 
#define EPS 1e-6
#define equals(a,b) (fabs(a-b) < EPS)
 
double A,B,C;
 
double f(double t){
    return A*t+B*sin(C*t*M_PI);
}
 
int main(){
    cin >> A >> B >> C;
    double L = 0, R = 10000000;
    for(int i = 0 ; i < 150 ; i++){
	double mid = (L + R) / 2;
	double res = f(mid);
	if(equals(res,100)){
	    printf("%.10f\n",mid);
	    break;
	}
	if(res < 100){
	    L = mid;
	}else{
	    R = mid;
	}
    }
    return 0;
}
