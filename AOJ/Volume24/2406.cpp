#include <stdio.h>
 
int main(){
    int N,T,E,x[10000],first=0,i,num=-1,flg=0;
 
    scanf("%d%d%d" ,&N ,&T ,&E);
    for( i = 0 ; i < N ; i++ ){
	scanf("%d" ,&x[i]);
     
	first = x[i];
	if( flg == 0 ){
	    while( x[i] <= (T+E) ){
		if( (T-E) <= x[i] && x[i] <= (T+E) ){
		    num = i+1; flg = 1;
		}
		x[i] += first;
	    }
	}
    }
    printf("%d\n" ,num); 
    return 0;
}
