#include <cstdio>
#include <cmath>
 
#define s(a) sin(a*M_PI/180)
#define S(a) (float)a
 
int main(){
    int n;
 
    while(scanf("%d" ,&n),n){
	double a1 = 0.0,a2 = 0.0,in,rem = 360;
	for(int i = 0 ; i < n-1 ; i++){
	    scanf("%lf" ,&in);
	    rem -= in;
	    a1 += s(in);
	}
	a1 += s(rem);
 
	scanf("%d" ,&n);
	rem = 360;
	for(int i = 0 ; i < n-1 ; i++){
	    scanf("%lf" ,&in);
	    rem -= in;
	    a2 += s(in);
	}    
	a2 += s(rem);
	if(S(a1) > S(a2)){
	    puts("1");
	}else if(S(a1) < S(a2)){
	    puts("2");
	}else{
	    puts("0");
	}
    }
    return 0;
}
