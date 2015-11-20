#include <iostream>

using namespace std;
 
int main(){
    int a,b;
    int n;
 
    while(cin >> a >> b >> n){
	int sum = 0;
	a *= 10;
 
	for(int i = 0 ; i < n ; i++){
	    sum += (a / b) % 10;
	    a %= b;
	    a *= 10;
	}
	cout << sum << endl;
    }
    return 0;
}
