#include <iostream>

using namespace std;
 
int main(){
    string s[] = {"BD","ACE","BF","AEG","BDFH"
		  ,"CEI","DH","EGI","FH"};
 
    for(int i = 0 ; i < 1000 ; i++){
	string str;
	bool possible = true;
 
	cin >> str;
	int size = str.size();
	for(int j = 1 ; j < size ; j++){
	    int k;
	    for(k = 0 ; k < s[str[j-1]-'A'].size() ; k++){
		if(str[j] == s[str[j-1]-'A'][k]){
		    break;
		}
	    }
	    if(k == s[str[j-1]-'A'].size()){
		possible = false;
		break;
	    }   
	}
	if(possible){
	    cout << str << endl;
	}
    }
    return 0;
}
