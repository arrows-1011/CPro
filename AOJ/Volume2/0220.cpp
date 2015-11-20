#include <iostream>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main(){
    double n;
 
    while(cin >> n , n >= 0){
	string ans = "",tmp = "";
	int integer = n;
 
	n -= integer;
 
	while(integer){
	    tmp += (integer % 2) + '0';
	    integer /= 2;
	}
 
	int len = (int)tmp.size();
	for(int i = len ; i < 8 ; i++){
	    tmp += "0";
	} 
 
	reverse(tmp.begin(),tmp.end());
	ans += tmp + ".";
 
	tmp = "";
 
	for(int i = 0 ; i < 4 ; i++){
	    double b = pow(2.0,-(i+1));
 
	    if(n == b){  
		tmp += "1";
		n -= b;
		break;
	    }
 
	    if((int)(n / b) == 0){
		tmp += "0";
	    }
	    else{
		tmp += "1";
		n -= b;
	    }
	}
 
	len = (int)tmp.size();
	for(int i = len ; i < 4 ; i++){
	    tmp += "0";
	}  
 
	if(!n) cout << ans + tmp << endl;
	else cout << "NA" << endl;
    }
    return 0;
}
