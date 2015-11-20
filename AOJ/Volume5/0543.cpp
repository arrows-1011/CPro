#include <stdio.h>
 
int main(){
    int total,i,pri;
    
    while(1){
	scanf("%d" ,&total);
	if( total == 0 ) break;
	i = 1;
	while( i < 10 ){
	    scanf("%d" ,&pri);
	    total -= pri;
	    i++;
	}
	printf("%d\n" ,total);
    }
    return 0;
}
