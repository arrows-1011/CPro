#include <iostream>

using namespace std;
 
int main(){
    int student[31],n;
 
    for( int i = 0 ; i < 31; i++ ) student[i] = 1;
    student[0] = 0;
    for( int i = 0 ; i < 28 ; i++ ){
	cin >> n;
	student[n] = 0;
    }
 
    for( int i = 0 ; i < 31 ; i++ ){
	if( student[i] == 1 ) cout << i << endl;
    }
    return 0;
}
