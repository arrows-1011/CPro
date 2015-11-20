#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int waseda[11],keiou[11],sumW=0,sumK=0;
 
    for( int i = 0 ; i < 10 ; i++ ) cin >> waseda[i];
    for( int i = 0 ; i < 10 ; i++ ) cin >> keiou[i]; 
 
    sort( waseda , waseda+10 );
    sort( keiou , keiou+10 );
 
    sumW = waseda[9]+waseda[8]+waseda[7];
    sumK = keiou[9]+keiou[8]+keiou[7];
    
    cout << sumW << " " << sumK << endl;
    return 0;
}
