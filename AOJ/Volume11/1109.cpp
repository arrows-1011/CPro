#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int z;
 
    while(cin >> z,z){
	long long ans = -1,z3 = z*z*z,res=9999999;    
 
	for(long long i = z-1 ; i >= 0 ; i--){
	    for(long long j = z-1 ; j >= 0 ; j--){
		ans = max(ans,i*i*i+j*j*j);
		if(ans <= z3){
		    res = min(res,z3-ans);
		}
		else ans = -1;
	    }
	}
	cout << res << endl;
    }
    return 0;
}
