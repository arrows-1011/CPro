#include <stdio.h>
 
int main(){
    int a,i,s = 0;
    for(i = 0 ; i < 4 ; i++){
	scanf("%d",&a);
	s += a;
    }
    printf("%d\n%d\n",s/60,s%60);
    return 0;
}
