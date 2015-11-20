#include <stdio.h>
 
int main(){
    int h,m,s;
     
    while(scanf("%d%d%d",&h ,&m ,&s)!=EOF){
        if(h==-1&&m==-1&&s==-1) break;
        int tl = (3600*2)-(3600*h+60*m+s) ,three = tl*3;
        printf("%02d:%02d:%02d\n" ,tl/60/60 ,tl/60%60 ,tl%60);
        printf("%02d:%02d:%02d\n" ,three/60/60 ,three/60%60 ,three%60);
    }
    return 0;
}
