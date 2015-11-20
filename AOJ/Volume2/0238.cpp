#include <iostream>

using namespace std;
 
int main(){
    int t,n,s,f,total;
 
    for(;;){
	total = 0;
 
	cin >> t;
	if( t == 0 ) break;
 
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
	    cin >> s >> f;
	    total += f - s;
	}
 
	if( total >= t ) cout << "OK" << endl;
	else cout << t - total << endl;
    }
    return 0;
}
