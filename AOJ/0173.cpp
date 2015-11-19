#include <iostream>

using namespace std;
 
int main(){
    string str;
    int b,a;
 
    while(cin >> str >> b >> a){
	cout << str << ' ' << b+a << ' ' << b*200+a*300 << endl;
    }
 
    return 0;
}
