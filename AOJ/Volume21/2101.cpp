#include <iostream>

using namespace std;
 
int main(){
    int N,sum;
 
    while(1){
	cin >> N;
	if( N == 0 ) break;
	sum = 0;
	for( int j = 1 ; j*j <= N; j++ ){
	    if( N % j == 0 ){ 
		sum += j;
		if( j*j != N ) sum += N/j;
	    }
	}
   
	sum -= N;
	if( N < sum ) cout << "abundant number" << endl;
	else if( N > sum ) cout << "deficient number" << endl;
	else cout << "perfect number" << endl;
    }
    return 0;
 
}
