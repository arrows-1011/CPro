#include <stdio.h>
 
int main(){
    char abc1,abc2,res;
    res = 'A';
    while(scanf("%c,%c" ,&abc1,&abc2) != EOF){
	if( abc1 == res && abc2 != abc1 ) res = abc2;
	else if( abc2 == res && abc2 != abc1 ) res = abc1; 
    }
    printf("%c\n" ,res);
    return 0;
}
