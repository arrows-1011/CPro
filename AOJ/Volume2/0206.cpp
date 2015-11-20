#include <iostream>

using namespace std;
  
int main(){
    int cost,M,N,cnt,yatta,flg,cnt1;
    
    while(1){
	cnt = yatta = flg = cnt1 = 0;
      
	cin >> cost;
	if( cost == 0 ) break;
  
	while(1){
  
     
	    if( cnt1 == 12 ) break;
  
	    cin >> M >> N;
  
	    if( flg == 0 ){
		yatta += (M - N);
		if( cost <= yatta ) flg = 1;
		cnt++;
	    }
	    cnt1++;
	}
	if( cost <= yatta ) cout << cnt << endl;
	else cout << "NA" << endl;
    }
    return 0;
}
