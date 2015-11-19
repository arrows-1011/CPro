#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>

using namespace std;
 
int main(){
    int n;
 
    while(cin >> n ,n != -1){
	complex<double> pos(1,0);
	double r;
	for(int i = 0 ; i < n-1 ; i++){
	    r = arg(pos);
	    pos.real() -= sin(r);
	    pos.imag() += cos(r);
	}
	printf("%.5f\n%.5f\n" ,pos.real(),pos.imag());
    }
    return 0;
}
