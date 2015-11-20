#include <bits/stdc++.h>
 
using namespace std;
 
double calc(double va,double vb,double ta,double tb){
    return (ta*va+tb*vb)/(va+vb);
}
 
int main(){
    double T,D,ta,tb,da,db;
    cin >> T >> D >> ta >> tb >> da >> db;
    double res = 1e9;
    for(int i = 0 ; i < 1010 ; i++){
	for(int j = 0 ; j < 1010 ; j++){
	    double va = da*i, vb = db*j;
	    if(i == 0 && j == 0) continue;
	    if(va + vb > D) continue;
	    res = min(res,abs(T-calc(va,vb,ta,tb)));
	}
    }
    printf("%.10f\n",res);
    return 0;
}
