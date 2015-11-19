#include <stdio.h>
 
int main(){
    double left,right;
    int la,ra,lb,rb,lc,rc,ld,rd;
     
    la = ra = lb = rb = lc = rc = ld = rd = 0;
    while(scanf("%lf%lf" ,&left ,&right) != EOF){
        if(left >= 1.1) la++;
        else if(0.6 <= left && left < 1.1) lb++;
        else if(0.2 <= left && left < 0.6) lc++;
        else ld++;
         
        if(right >= 1.1) ra++;
        else if(0.6 <= right && right < 1.1) rb++;
        else if(0.2 <= right && right < 0.6) rc++;
        else rd++;
    }
    printf("%d %d\n%d %d\n%d %d\n%d %d\n" ,la,ra,lb,rb,lc,rc,ld,rd);
    return 0;
}
