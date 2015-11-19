#include <cstdio>
 
int main(){
    int N;
    while(~scanf("%d" ,&N)){
	printf("3C%02d\n" ,N % 39 ? N % 39 : 39);
    }
    return 0;
}
