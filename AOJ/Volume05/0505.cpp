#include <iostream>
#include <algorithm>
 
using namespace std;

int main(){
 
    int A;
    int n,m;
    int count[101];
 
    while(1){
 	cin >> n >> m ;
 
	if( n == 0 && m == 0 ) break;
	for(int i = 0; i < m ; i++ ) count[i] = m - i;
 
	for( int i = 0 ; i < n ; i++ ){
	    for( int j = 0 ; j < m ; j++ ){
		cin >> A;
		if( A == 1 ) count[j] += 1000; 
	    }
	}
 
	sort( count , count + m );
	cout << 1 + m - ( count[ m - 1 ] % 1000);
   
	for( int i = m - 2 ; i >= 0 ; i-- ){
	    cout << " " << 1 + m - ( count[ i ] % 1000);
	}
	cout << endl;
    }
    return 0;
}
