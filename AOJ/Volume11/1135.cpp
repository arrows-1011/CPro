#include <iostream>

using namespace std;
  
int main(){
    int n,year,ope,bfmoney,tax,interest,max,get,tempmoney=0;
    double up_yatta,temp;
    
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
	max = 0;
	cin >> bfmoney;
	cin >> year >> ope;
  
	tempmoney = bfmoney;
	for( int j = 0 ; j < ope ; j++ ){
	    get = 0;temp = 0;
	    bfmoney = tempmoney;
	    cin >> interest >> up_yatta >> tax;
        
	    if( interest == 1 ){
		for( int k = 0 ; k < year ; k++ ){
		    get = up_yatta * bfmoney;
		    bfmoney += get - tax;
		}  
	    }
	    else{
		for( int k = 0 ; k < year ; k++ ){
		    temp = bfmoney * up_yatta;
		    get += temp;
		    bfmoney -= tax;
		}
      
		bfmoney += get;
	    }
	    if( max < bfmoney ) max = bfmoney;
	}       
	cout << max << endl;
    }
    return 0;
}
