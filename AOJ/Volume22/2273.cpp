#include <iostream>
#include <map>
 
using namespace std;
 
int main(){
    string s = "abcd";
    string AI;
    map<string,bool> judge;
 
    judge[s] = true;
 
    while(true){
	cout << "?" << s << endl;
	cin >> AI;
 
	if(s[s.size()-1] != AI[0] || judge[AI]){
	    cout << "!OUT" << endl;
	    break;
	}
	judge[AI] = true;
 
	s[0] = AI[AI.size()-1];
	for(int i = 1 ; i < 3 ; i++){
	    if(s[i] < 122){
		s[i]++;
		break;
	    }
	}
    }
    return 0;
}
