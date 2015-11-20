#include <iostream>
#include <cmath>
#include <cstdio>
 
using namespace std;
 
double s(double a,double b,double c){
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
 
int main(){
    double a,l,x;
    while(cin >> a >> l >> x){
        double y = (l+x)/2;
        printf("%.15f\n",s(a,l,l)+s(y,y,l)*2);
    }
    return 0;
}
