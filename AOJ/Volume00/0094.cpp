#include <iostream>
#include <cstdio>

using namespace std;

#define tubo 3.305785
 
double ans(int a,int b){
    return (a*b)/tubo; 
}
 
int main(){
    int a,b;
    cin >> a >> b;
    printf("%.6f\n" ,ans(a,b));
    return 0;
}
