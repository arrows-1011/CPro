#include <iostream>

using namespace std;

#define MAX 1000000

int main(){
    int n;
    bool isPrime[MAX];
 
    for( int i = 0 ; i <= MAX ; i++ ) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
 
    for( int i = 2 ; i*i <= MAX ; i++ ){
	if( isPrime[i]){
	    for( int j = 2*i ; j <= MAX ; j += i ){
		isPrime[j] = false;
	    }
	}
    }
    
    while(cin >> n){
	int cnt = 0;
	for( int i = 2 ; i <= n ; i++ ){
	    if( isPrime[i] ) cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
