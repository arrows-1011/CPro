#include <iostream>

using namespace std;
 
int main(){
    int Q,A,qq[4],aa[4],Hit,Blow,num;
 
    while(1){ 
	num = 1000;
	Hit = Blow = 0;
 
	cin >> Q >> A;
	if( Q == 0 && A == 0 ) break;
 
	for( int i = 0 ; i < 4 ; i++ ){
 
	    qq[i] = Q / num % 10;
	    aa[i] = A / num % 10;
	    num/=10;
 
	}
 
	for( int i = 0 ; i < 4 ; i++ ){
	    for( int j = 0 ; j < 4 ; j++ ){
 
		if( qq[i] == aa[j] && i == j ) Hit++;
		else if( qq[i] == aa[j] && i != j ) Blow++;
 
	    }
	}
	cout << Hit << " " << Blow << endl;
    }
    return 0;
}
