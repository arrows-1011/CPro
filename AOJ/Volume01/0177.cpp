#include <cstdio>
#include <cmath>
 
#define r 6378.1
 
int main()
{
    double a, b, c, d;
 
    while (true) {
	scanf("%lf %lf %lf %lf" ,&a ,&b ,&c ,&d);
	if (a == -1 && b == -1 && c == -1 && d == -1) {
	    break;
	}
 
	a = a * M_PI / 180;
	b = b * M_PI / 180;
	c = c * M_PI / 180;
	d = d * M_PI / 180;
 
	double e = cos(a)*cos(b);
	double f = sin(b)*cos(a);
	double g = sin(a);
	double h = cos(c)*cos(d);
	double i = sin(d)*cos(c);
	double j = sin(c);
 
	double dist = acos(e*h + f*i + g*j);  
	printf("%d\n", (int)(r*dist+0.5));
    }
    return 0;
}
