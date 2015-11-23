#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int A,res = 0;
    cin >> A;
    for(int x = 0 ; x <= 100 ; x++){
	for(int y = 0 ; y <= 100 ; y++){
	    if(x + y == A){
		res = max(res,x*y);
	    }
	}
    }
    cout << res << endl;
    return 0;
}
