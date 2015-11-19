#include <iostream>
#include <sstream>
 
using namespace std;
 
int main(){
    string in;  
 
    while(getline(cin,in) ,in != "0"){
	stringstream s(in);
	int sum = 0,n;
	bool flg = false;
 
	while(s >> n){
	    if(2 <= n && n <= 9){
		sum += n;
	    }else if(n >= 10){
		sum += 10;
	    }else{
		sum++;
		flg = true;
	    }
	}
 
	if(sum <= 11 && flg){
	    sum += 10;
	} 
	if(sum > 21){
	    cout << 0 << endl;
	}else{
	    cout << sum << endl;
	}
    }
    return 0;
}
