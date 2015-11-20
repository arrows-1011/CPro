#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int n,m;
    int sumT,sumH;
    int bt,bh;
    int flag;
 
    while(1){
	sumT = sumH = 0;
	bt = bh = flag = 0;
	int t[150],h[150];
	
	cin >> n >> m;
	if( n == 0 && m == 0 ) break;
 
	for( int i = 0 ; i < n ; i++ ){
	    cin >> t[i];
	    sumT += t[i];
	}
	
	sort( t , t+n ); 
 
	for( int j = 0 ; j < m ; j++ ){
	    cin >> h[j];
	    sumH += h[j];
	}
 
	sort( h , h+m );
 
	for( int i = 0 ; i < n ; i++ ){
	    for( int j = 0 ; j < m ; j++ ){
		if( flag == 0){
		    bt = t[i];
		    bh = h[j];
		    sumT = sumT + bh - bt;
		    sumH = sumH + bt - bh;
 
		    if( sumT == sumH ) flag = 1;
		    else{
			sumT = sumT - bh + bt;
			sumH = sumH - bt + bh;
		    }        
		}
	    }
	}
	if( flag == 1 ) cout << bt <<" "<< bh << endl;
	else cout << "-1" << endl;
    }
    return 0;
   
}
