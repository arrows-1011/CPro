#include <iostream>

using namespace std;
 
int main(){
    int N;
    int cnt;
 
    while(1){
	cnt = 0;
 
	cin >> N;
	if( N == 0 ) break;
	for( int a = 1 ; a <= N/2 ; a++ ){
	    for( int n = 2 ; n <=N ; n++ ){
		if( n*( 2*a + ( n - 1 ) ) / 2 == N ) cnt++;
	    }
	}
	cout << cnt << endl;
    }
    return 0;
}
