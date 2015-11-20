#include <stdio.h>
 
int main(){
    int i,j,n,k;
    int a[100000];
    int sum,ans;
 
    while(1){
	sum = ans = 0;
 
	scanf("%d%d" ,&n ,&k);
	if(n == 0 && k == 0) break;
 
	for(i = 0 ; i < n ; i++){
	    scanf("%d" ,a + i);
	}
     
	for(i = 0 ; i < k ; i++){
	    sum += a[i];
	}
     
	ans = sum;
     
	for(j = 0 ; j < n - k ; j++){
	    sum -= a[j];
	    sum += a[j+k];
	    if(ans < sum) ans = sum;
	}
	printf("%d\n" ,ans);
    }
    return 0;
}
