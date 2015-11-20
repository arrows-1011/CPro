#include <bits/stdc++.h>
 
using namespace std;
  
#define EPS 1e-6
#define INF 1e8
typedef complex<double> P;
  
double dot(P a,P b){
    return real(conj(a)*b);
}
  
double cross(P a,P b){
    return imag(conj(a)*b);
}
  
struct Point{
    double x,y;
};
  
int main(){
    double D;
  
    while(scanf("%lf",&D), D){
	Point v,p;
      
	scanf("%lf%lf%lf%lf",&p.x,&p.y,&v.x,&v.y);
	P np = P(p.x,p.y), nv = P(v.x,v.y);
	double dist = INF;
  
	if(abs(cross(np,nv)) < EPS){
	    if(dot(np,nv) < -EPS){
		dist = abs(np);
	    }else{
		dist = 2-abs(np);
	    }
	}
     
	if(dist < D){
	    printf("%.8f\n",dist);
	}else{
	    printf("impossible\n");
	}
    }
    return 0;
}
