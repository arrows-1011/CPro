#include <iostream>

using namespace std;
 
#define true 1;
#define false 0;
 
int main(){
    int n,cnt,N=123456;
    char is_prime[1000000];
   
    for( int i = 0 ; i <= 2*N ; i++ ) is_prime[i] = true;
   
    is_prime[0] = is_prime[1] = false; 
   
    for( int i = 2 ; i*i <= 2*N ; i++ ){
	if( is_prime[i] ){
	    for( int j = i*2 ; j <= 2*N ; j += i ){
		is_prime[j] = false;
	    }
	}
    }
   
    while(1){
	cnt = 0;
 
	cin >> n;
	if( n == 0 ) break;
 
	for( int i = n + 1 ; i <= 2*n ; i++ ){
	    if( is_prime[i] ) cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
