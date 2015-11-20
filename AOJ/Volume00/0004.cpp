#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    double a,b,c,d,e,f,x,y;
    while(cin >> a >> b >> c >> d >> e >> f){
	x = (c*e - b*f)/(a*e - b*d);
	y = (a*f - c*d)/(a*e - b*d);
	if(x == 0) x = 0.000;
	if(y == 0) y = 0.000;
	printf("%.3f %.3f\n",x,y);
    }
    return 0;
}
