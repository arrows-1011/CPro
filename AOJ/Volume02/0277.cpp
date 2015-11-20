#include <iostream>

using namespace std;
 
int main(){
    int t,n;
 
    for(int i = 0 ; i < 4 ; i++){
	cin >> t >> n;
 
	switch(t){
	case 1:
	    cout << n*6000 << endl;
	    break;
	case 2:
	    cout << n*4000 << endl;
	    break;
	case 3:
	    cout << n*3000 << endl;
	    break;
	default:
	    cout << n*2000 << endl;
	}
    }
    return 0;
}
