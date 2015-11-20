#include <iostream>
#include <algorithm>

using namespace std;
 
int main(){
    int x,y,b,p,n;
 
    cin >> n;
    while(n--){
	cin >> x >> y >> b >> p;
	if(b >= 5 && p >= 2){
	    cout << (x*b+y*p)*0.8 << endl;
	}
	else if(b >= 5 && p < 2){
	    double tmp = (x*b+y*p);
	    p = 2;
	    cout << min(tmp,(x*b+y*p)*0.8) << endl;
	}
	else if(b < 5 && p >= 2){
	    double tmp = (x*b+y*p);
	    b = 5;
	    cout << min(tmp,(x*b+y*p)*0.8) << endl;
	}
	else cout << x*b+y*p << endl;
    }
    return 0;
}
