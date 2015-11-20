#include<stdio.h>
 
int main(){
    int n,array[5]={0},i,a=0,b=0,c=0,j;
   
    scanf("%d",&n);
    for(i = 0;i < n ;i++ ){
	if(i == 0)  scanf("%d" ,&array[i]);
	else scanf(" %d",&array[i]);
	if(n == 2){
	    if( array[0] == array[1]){
		printf("1\n");
	    }
	    else if( array[0] < array[1] ){
		a = array[1];
		b = array[0];
	    }
	    else if( array[0] > array[1] ){
		a = array[0];
		b = array[1];
	    }
	    for( j = 1 ; j <= b ; j++ ){
		if( a % j == 0 && b % j == 0 ){
		    printf("%d\n",j);
		}
	    }
	}
     
	if(n == 3){
	    if( array[0] == array[1] && array[1] == array[2] ){
		printf("1\n");
	    }
	    else if(array[0] < array[1] && array[1] < array[2]){
		a = array[2];
		b = array[1];
		c = array[0];
	    }
	    else if(array[0] < array[2] && array[2] < array[1]){
		a = array[1];
		b = array[2];
		c = array[0];
	    }
	    else if(array[1] < array[0] && array[0] < array[2]){
		a = array[2];
		b = array[0];
		c = array[1];
	    }
	    else if(array[1] < array[2] && array[2] < array[0]){
		a = array[0];
		b = array[2];
		c = array[1];
	    }
	    else if(array[2] < array[0] && array[0] < array[1]){
		a = array[1];
		b = array[0];
		c = array[2];
	    }
	    else if(array[2] < array[1] && array[1] < array[0]){
		a = array[0];
		b = array[1];
		c = array[2];
	    }
     
	    for( j = 1 ; j <= c ; j++ ){
		if( a % j == 0 && b % j == 0 && c % j == 0 ){
		    printf("%d\n",j);
		}
	    }
	}
    }
    return 0;
}
