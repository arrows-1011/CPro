#include <stdio.h>
 
int main(){
    int n,y,m,d,D,cnt,i;
    
    scanf("%d" ,&n);
    for( i = 0 ; i < n ; i++ ){
	cnt = 0;
	scanf("%d %d %d" ,&y ,&m ,&d);
  
	while(1){
	    if( y == 1000 && m == 1 && d == 1 ) break; 
	    d++; cnt++;
	    if( y % 3 == 0 || m % 2 == 1 ){
		D = 20;
		if( d > D ){ d = 1; m++; }
	    }
	    else{
		D = 19;
		if( d > D ){ d = 1; m++; }
	    }
	    if( m > 10 ){ y++; m = 1; }   
	}
	printf("%d\n" ,cnt);
    }
    return 0;
}
