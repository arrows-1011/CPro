#include <iostream>
#include <string>
#include <sstream>

using namespace std;
 
int main(){
    string str;
    int sum = 0,num;
 
    while(getline(cin,str)){
	for(int i = 0 ; i < (int)str.size() ; i++){
	    if('0' <= str[i] && str[i] <= '9') continue;
	    else str[i] = ' ';
	}
	stringstream s;
	s << str;
	while(s >> num){
	    sum += num;
	}
    }
    cout << sum << endl;
    return 0;
}
