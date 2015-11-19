#include <iostream>

using namespace std;

int main(){
    int a,b;
    while(cin >> a >> b){
	int c = 0;
	a += b;
	while(a > 0){
	    c++;
	    a /= 10;
	}
	cout << c << endl;
    }
    return 0;
}
