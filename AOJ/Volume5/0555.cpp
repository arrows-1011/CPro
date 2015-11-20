#include <stdio.h>
#include <string.h>
 
int main(){
    char Word[20],Ring[20],temp[20];
    int n,i,cnt = 0;
 
    scanf("%s" ,Word);
    scanf("%d" ,&n);
 
    for( i = 0 ; i < n ; i++ ){
	scanf("%s" ,Ring);
	strcpy( temp , Ring ); 
	strcat( Ring , temp );
	if( strstr( Ring , Word ) ) cnt++;
    }
    printf("%d\n" ,cnt );
 
    return 0;
} 
