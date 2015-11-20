#include <iostream>

using namespace std;

int main(){
    string s;
    getline(cin,s);
    for(int i = 0 ; i < (int)s.size() ; i++){
	cout << (char)toupper(s[i]);
    }
    cout << endl;
    return 0;
}
