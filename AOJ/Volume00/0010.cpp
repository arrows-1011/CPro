#include <cstdio>
#include <cmath>
  
int main(){
    double x1,x2,x3,y1,y2,y3,r,xp,yp;
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
 
	xp = (y2-y3)*(x1*x1+y1*y1)+(y3-y1)*(x2*x2+y2*y2)+(y1-y2)*(x3*x3+y3*y3);
	xp /= 2*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
	yp = (x2-x3)*(x1*x1+y1*y1)+(x3-x1)*(x2*x2+y2*y2)+(x1-x2)*(x3*x3+y3*y3);
	yp /= 2*(y1*(x2-x3)+y2*(x3-x1)+y3*(x1-x2));
	r = sqrt((x1-xp)*(x1-xp)+(y1-yp)*(y1-yp));
	printf("%.3lf %.3lf %.3lf\n",xp,yp,r);
    }
    return 0;
}
