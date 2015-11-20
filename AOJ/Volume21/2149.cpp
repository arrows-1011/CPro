#include <iostream>

using namespace std;
 
int main(){
    int n,A,B,C,xbe,xaf,cnt,flag,y;
 
    while(1){
	cnt = 0; flag = 0;
 
	cin >> n >> A >> B >> C >> xbe;
	if( n == 0 && A == 0 && B == 0 && C == 0 && xbe == 0 ) break;
 
	for( int i = 0 ; i < n ; i++ ){
	    cin >> y;
 
	    if(flag==1)continue;
	    while(1){
		if(xbe == y){
		    xaf = ( A * xbe + B ) % C;
		    xbe = xaf;
		    cnt++;
		    break;
		}
 
		xaf = ( A * xbe + B ) % C;
		xbe = xaf;
		cnt++;
 
		if( cnt > 10000 ){
		    cout << "-1" << endl;
		    flag = 1;
		    break;
		}
	    }
	}
	if( flag==0 ) cout << cnt-1 << endl;
    }
    return 0;
}
