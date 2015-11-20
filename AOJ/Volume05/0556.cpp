#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n,k,a,b,tile;
   
    cin >> n >> k;   
    for( int i = 0 ; i < k ; i++ ){
	cin >> a >> b;
	a = min( a , n - a + 1 );
	b = min( b , n - b + 1 );    
	tile = min( a , b ) % 3;
	if( tile == 0 ) tile = 3;
	cout << tile << endl;    
    }
    return 0;
}
