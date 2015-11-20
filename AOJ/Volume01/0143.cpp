#include <complex>
#include <cmath>
#include <cstdio>
  
using namespace std;
  
typedef double D;
typedef complex<D> P;
#define EPS (1e-10)
 
D dot(P a,P b){
    return real(conj(a) * b);
}
 
D cross(P a,P b){
    return imag(conj(a) * b);
} 
 
int ccw(P p0,P p1,P p2){
    P a = p1 - p0;
    P b = p2 - p0;
  
    if(cross(a,b) > EPS) return 1;
    if(cross(a,b) < -EPS) return -1;
    if(dot(a,b) < -EPS) return 2;
    if(norm(a) < norm(b)) return -2;
    return 0;
}
 
bool check(P p1,P p2,P p3,P p4){
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 &&
	    ccw(p3,p4,p1)*ccw(p3,p4,p2) <= 0);
}
  
int main(){
    int n;
    P P[3],T[2];
  
    scanf("%d" ,&n);
    while(n--){
	for(int i = 0 ; i < 3 ; i++){
	    scanf("%lf %lf" ,&P[i].real() ,&P[i].imag());
	}
 
	for(int i = 0 ; i < 2 ; i++){
	    scanf("%lf %lf" ,&T[i].real() ,&T[i].imag());
	}
 
	int cnt = 0; 
	if(check(P[0],P[1],T[0],T[1])){
	    cnt++;
	}   
	if(check(P[0],P[2],T[0],T[1])){
	    cnt++;
	} 
	if(check(P[1],P[2],T[0],T[1])){
	    cnt++;
	} 
	if(cnt % 2){
	    puts("OK");
	}else{
	    puts("NG");
	}
    }
    return 0;
}
