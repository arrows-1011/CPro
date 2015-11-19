#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
 
int main(){
    double q;
     
    while(cin >> q, q != -1){
        double x = q/2;
         
        while(true){
            x -= (pow(x,3)-q)/(3*pow(x,2));
            if(abs(pow(x,3)-q) < 0.00001*q) break;
        }
        printf("%.6f\n" ,x);
    }
    return 0;
}
