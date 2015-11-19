#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main(){
    int n;
 
    scanf("%d" ,&n);
    while(n--){
	double h,m;
	scanf("%lf:%lf" ,&h ,&m);
     
	double l = 30*h + m/2;
	double s = m * 6.0;
 
	double key = fabs(l-s);
	key = min(key,360-key);
   
	if(0 <= key && key < 30){
	    puts("alert");
	}else if(90 <= key && key <= 180){
	    puts("safe");
	}else{
	    puts("warning");
	} 
    }
    return 0;
}
