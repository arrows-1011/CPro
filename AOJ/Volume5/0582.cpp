#include <stdio.h>
#include <math.h>
 
int main(){
    int a,b,c;
    int e=0,t=0,d=0;
    int s=0;
 
    while(1){
	scanf("%d %d %d" ,&a ,&b ,&c);
	if((fabs(a-b) < c && a + b > c)){
	    s++;
	    if((a*a + b*b < c*c)||(a*a + c*c < b*b) ||(b*b + c*c < a*a) ) d++;
	    else  if((a*a + b*b == c*c) ||( a*a + c*c == b*b) || (b*b + c*c == a*a) ) t++;
	    else if((a*a + b*b > c*c) ||(a*a + c*c > b*b) ||(b*b + c*c > a*a)) e++;
	}
	else break;
    }
    printf("%d %d %d %d\n" ,s ,t ,e ,d);
    return 0;
}
