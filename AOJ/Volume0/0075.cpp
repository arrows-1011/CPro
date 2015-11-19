#include <stdio.h>
 
int main(){
    int num;
    double Wei,Hei,BMI;
 
    while(scanf("%d,%lf,%lf" ,&num ,&Wei ,&Hei) != EOF){
	BMI = Wei / (Hei*Hei); 
	if(BMI >= 25) printf("%d\n" ,num);
    }
    return 0;
}
