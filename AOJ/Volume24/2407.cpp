#include <stdio.h>
#include <string.h>
 
int main(){
    char N[51];
    scanf("%s" ,N);
    if( N[0] ==  N[strlen(N)-1] ){
	printf("%c\n",N[0]);
    }else{
	printf("o\n");
    }
    return 0;
}
