#include <stdio.h>
 
void judge(double);
 
int main(){
    double weight;
    while(scanf("%lf",&weight) != EOF){
	judge(weight);
    }
    return 0;
}
 
void judge(double weight){
 
    if( weight <= 48 ) printf("light fly\n");
    else if( weight <= 51 ) printf("fly\n");
    else if( weight <= 54 ) printf("bantam\n");
    else if( weight <= 57 ) printf("feather\n");
    else if( weight <= 60 ) printf("light\n");
    else if( weight <= 64 ) printf("light welter\n");
    else if( weight <= 69 ) printf("welter\n");
    else if( weight <= 75 ) printf("light middle\n");
    else if( weight <= 81 ) printf("middle\n");
    else if( weight <= 91 ) printf("light heavy\n");
    else printf("heavy\n");
}
