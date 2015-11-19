#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
 
int main(){
    double S,x,h;
 
    for(;;){
	cin >> x >> h;
	if(x == 0 && h == 0) break;
	S = (sqrt(h*h+x*x/4)*2+x)*x;
	printf("%.6f\n" ,S);
    }
    return 0;
}
