#include <iostream>

using namespace std;
 
int main(){
    double v;
    int N;
    while(cin >> v){
	N = v*v/98+2;    
	cout << N << endl;
    }
    return 0;
}
