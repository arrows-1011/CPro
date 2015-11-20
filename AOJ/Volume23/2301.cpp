#include <bits/stdc++.h>
 
using namespace std;
 
double P,E,T;
 
double solve(double L,double R,int K){
    double H = (L + R) / 2.0;
    if(K == 0){
	if(T-E <= H && H <= T+E){
	    return 1;
	}else{
	    return 0;
	}
    }
 
    if(T-E <= L && L <= T+E &&
       T-E <= R && R <= T+E){
	return 1;
    }
 
    if(T-E > L || T+E < R){
	return 0;
    }
 
    double res = 0;
    if(H < T){
	res += solve(L,H,K-1)*(1-P);
	res += solve(H,R,K-1)*P;
    }else{
	res += solve(H,R,K-1)*(1-P);
	res += solve(L,H,K-1)*P;
    }
    return res;
}
 
int main(){
    int K;
    double R,L;
    cin >> K >> R >> L >> P >> E >> T;
    printf("%.8f\n",solve(L,R,K));
    return 0;
}
