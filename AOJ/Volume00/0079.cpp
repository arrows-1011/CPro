#include <bits/stdc++.h>

#define MAX 21
 
double dis(double x1, double y1, double x2, double y2)
{
    double d;
    d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return d;
}
 
int main()
{
    double x[MAX], y[MAX];
    int t = 0;
    double S = 0.0, z, a, b, c;
 
    while (1) {
	if(scanf("%lf,%lf",&x[t] ,&y[t]) == EOF) break;
	t++;
    }
 
    for (int i = 2; i < t; i++) {
	a = dis(x[0], y[0], x[i-1], y[i-1]);
	b = dis(x[0], y[0], x[i], y[i]);
	c = dis(x[i-1], y[i-1], x[i], y[i]);
	z = (a + b + c) / 2;
 
	S += sqrt(z * (z - a) * (z - b) * (z - c));
    }
    printf("%.6f\n", S);
    return 0;
}
