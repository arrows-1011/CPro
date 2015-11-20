#include <iostream>
#include <string>

using namespace std;
 
int c[128];
 
void init(){
    c['I'] = 1;   c['V'] = 5;   c['X'] = 10;   c['L'] = 50; 
    c['C'] = 100; c['D'] = 500; c['M'] = 1000;
}
 
int main(){
    string str;
 
    init();
    while(cin >> str){
	int sum = 0;
	for(int i = 0 ; i < str.size()-1 ; i++){
	    sum += c[str[i]]*((c[str[i]] < c[str[i+1]]) ? -1 : 1);
	}
	sum += c[str[str.size()-1]];
	cout << sum << endl;
    }
    return 0;
}
