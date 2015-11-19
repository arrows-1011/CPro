#include <stdio.h>
 
int main(){
    int tr[10],v1,v2;
   
    while(~scanf("%d",&tr[0])){
        double a = 0;
        int sum = tr[0];
        for(int i = 1 ; i < 10 ; i++){
            scanf(",%d",&tr[i]);
            sum += tr[i];
        }
        scanf(",%d,%d",&v1,&v2);
         
        a = v1*((double)sum/(v1+v2));
         
        sum = 0;
        for(int i = 0 ; i < 10 ; i++){
            sum += tr[i];
            if(a <= sum){
                printf("%d\n" ,i+1);
                break;
            }
        }
    }
    return 0;
}
