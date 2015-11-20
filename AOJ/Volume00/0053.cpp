#include <stdio.h>
#define DATA 1000000
 
int prime[DATA];
 
void make(){
    for(int i = 0 ; i < DATA ; i++) prime[i] = 0;
  
    prime[0] = prime[1] = 1;
   
    for(int i = 2; i*i < DATA ; i++){
	if(prime[i] == 0){
	    for(int j = 2*i ; j < DATA ; j += i){
		prime[j] = 1;
	    }
	}
    }
}
 
int main(){
    int n,sum;
 
    make();
    for(;;){
	sum = 0;
	scanf("%d" ,&n);
	if(n == 0) break;
	for(int i = 0 ; n > 0 ; i++){
	    if(prime[i] == 0){
		sum += i;
		n--;
	    }    
	} 
	printf("%d\n" ,sum);   
    }    
    return 0;
}
