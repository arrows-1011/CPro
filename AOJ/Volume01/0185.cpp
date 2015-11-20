#include <cstdio>
 
#define MAX 1000000
 
bool prime[MAX];
 
void make(){
    for(int i = 0 ; i < MAX ; i++){
	prime[i] = true;
    }
 
    prime[0] = prime[1] = false;
    for(int i = 2 ; i*i < MAX ; i++){
	if(prime[i]){
	    for(int j = 2*i ; j < MAX ; j += i){
		prime[j] = false;
	    }
	}
    }
}
 
int main(){
    make();
    int n;
    while(scanf("%d" ,&n),n){
	int cnt = 0;
	for(int i = 2 ; i+i <= n ; i++){
	    if(prime[i] && prime[n-i]){
		cnt++;
	    }
	} 
	printf("%d\n" ,cnt);
    }
    return 0;
}
