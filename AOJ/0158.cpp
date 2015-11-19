#include <iostream>
using namespace std;
 
int main(){
    int n;
 
    while(cin >> n ,n){
	int cnt = 0;
	while(n != 1){
	    cnt++;
	    if(n %2 == 0){
		n /= 2;
	    }
	    else{
		n *= 3;
		n++;
	    }
	}
	cout << cnt << endl;
    }
    return 0;
}
