#include <cstdio>
#include <cmath>
 
const int price[7][7] = {
    {-1,300,500,600,700,1350,1650},
    {-1,-1,350,450,600,1150,1500},
    {-1,-1,-1,250,400,1000,1350},
    {-1,-1,-1,-1,250,850,1300},
    {-1,-1,-1,-1,-1,600,1150},
    {-1,-1,-1,-1,-1,-1,500}
};
 
const int dist[7][7] = {
    {-1,6,13,18,23,43,58},
    {-1,-1,7,12,17,37,52},
    {-1,-1,-1,5,10,30,45},
    {-1,-1,-1,-1,5,25,40},
    {-1,-1,-1,-1,-1,20,35},
    {-1,-1,-1,-1,-1,-1,15}
};
 
const int start = 17*60 + 30 , end = 19*60 + 30;
 
int main(){
    int sIC,sh,sm,tIC,th,tm;
 
    while(scanf("%d" ,&sIC) ,sIC){
	scanf("%d%d" ,&sh ,&sm);
	scanf("%d%d%d" ,&tIC ,&th ,&tm);
 
	sIC--; tIC--;
	bool ok1 = 0,ok2 = 0;
	int ssum = sh*60 + sm , tsum = th*60 + tm;
 
	if((start <= ssum && ssum <= end) ||
	   (start <= tsum && tsum <= end)) ok1 = 1;
 
	if(dist[sIC][tIC] <= 40) ok2 = 1;
  
	int ans = price[sIC][tIC];
	if(ok1 && ok2){
	    ans = (ans / 50 + 1) / 2;
	    ans *= 50;
	}
	printf("%d\n" ,ans);
    }
    return 0;
}
