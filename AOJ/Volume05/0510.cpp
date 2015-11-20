#include <stdio.h>
 
#define max(a,b) (a < b ? b : a)
 
int main(){
    int A = 0,B = 0,in,i;
    for(i = 0 ; i < 4 ; i++){
	scanf("%d",&in);
	A += in;
    }
    for(i = 0 ; i < 4 ; i++){
	scanf("%d",&in);
	B += in;
    }
    printf("%d\n",max(A,B));
    return 0;
}
