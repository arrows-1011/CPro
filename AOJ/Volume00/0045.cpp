#include <stdio.h>
 
int main(){
    int cost,num,totalcost = 0,cnt = 0;
    int avenum = 0;
 
    while(scanf("%d,%d" , &cost, &num) != EOF){
	cnt++;
	avenum += num;
	totalcost += cost*num;
    }
    printf("%d\n%d\n",totalcost ,(int)((double)avenum/(double)cnt+0.5));
    return 0;
}
