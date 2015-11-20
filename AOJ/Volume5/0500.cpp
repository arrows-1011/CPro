#include <stdio.h>
 
int main(){
 
    int A,B;
    int n;
    int i;
    int PointA,PointB;
 
    while(1){
 
	PointA = 0;
	PointB = 0;
 
	scanf("%d" ,&n);
 
	if( n == 0 ) break;
	for( i = 0 ; i < n ; i++ ){
 
	    scanf("%d %d" ,&A ,&B);
 
	    if( A < B ) PointB += A + B; 
      
	    if( A > B ) PointA += B + A;
 
	    if( A == B ){ 
		PointA += A;
		PointB += B;
	    }
	}
	printf("%d %d\n" ,PointA ,PointB);
    }
    return 0;
}
