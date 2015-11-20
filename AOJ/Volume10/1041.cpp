#include <iostream>

using namespace std;
  
int main(){
  
    int n,sum,point;
  
    while(1){
	sum = 0;
	cin >> n;
	if( n == 0 ) break;
	for( int i = 0 ; i < n/4 ; i++ ){
	    cin >> point;
	    sum += point;
	}
	cout << sum << endl;
    }
    return 0;
}
