#include <iostream>

using namespace std;
 
int main(){
    int n,m,Ci,Co,max,Ct,flag=0;
 
    cin >> n;
    cin >> m;
    Ct = m;
    max = m;
    for( int i = 0 ; i < n ; i++ ){
	cin >> Ci >> Co;
	Ct += Ci - Co;
	if( Ct < 0 ) flag = 1;
	if( max < Ct ) max = Ct;
    }
    if( flag == 1 ) cout << "0" << endl;
    else cout << max << endl;
    return 0;
}
