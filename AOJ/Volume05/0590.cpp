#include <stdio.h>
 
int main(){
    int N , ans = 0,S ,y;
    scanf("%d" ,&N);
    while(N--){
	scanf("%d" ,&S);
 
	int flg = 0;
	for(y = 1 ; 2*y*y <= S ; y++){
	    if((S - y) % (2*y + 1) == 0){
		flg = 1;
		break;
	    }
	}
	if(!flg){
	    ans++;
	}
    }
    printf("%d\n" ,ans);
    return 0;
}
