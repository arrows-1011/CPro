#include <stdio.h>
 
int cnt=0;
 
int GCD( int x , int y ){
    int tmp;
    if(!(x >= y )){
	tmp = x;
	x = y;
	y = tmp;
    }
    while(1){
	if( y == 0 ) break;
	x %= y;
	tmp = x;
	x = y;
	y = tmp;
	cnt++;
    }
    return x;
}
 
int main(){
    int x,y,ans;
   
    while(1){
	cnt = 0;
	scanf("%d %d" ,&x ,&y);
	if( x == 0 && y == 0 ) break;
     
	ans = GCD(x,y);
	printf("%d %d\n" ,ans,cnt);
    }
    return 0;
}
