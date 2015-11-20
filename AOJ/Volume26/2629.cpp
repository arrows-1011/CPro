#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    double d;
    scanf("%lf",&d);
    printf("%.12f\n",max((int)d+1.,d/sqrt(2.0)*2));
    return 0;
}
