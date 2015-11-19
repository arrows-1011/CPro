#include <cstdio>
#include <cmath>
 
int main(){
    int a,b,c,x = 0,y = 0;
    while(scanf("%d,%d,%d" ,&a,&b,&c) != EOF){
        if(pow(a,2)+pow(b,2)==pow(c,2)) x++;
        if(a == b) y++;
    }
    printf("%d\n%d\n" ,x ,y);
    return 0;
}
