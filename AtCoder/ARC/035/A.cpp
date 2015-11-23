#include <bits/stdc++.h>
 
using namespace std;
 
bool isP(const string &s){
    for(int i = 0 ; i < s.size()/2 ; i++){
	if(s[i] != s[s.size()-1-i]){
	    if(s[i] != '*' && s[s.size()-1-i] != '*'){
		return false;
	    }
	}
    }
    return true;
}
 
int main(){
    string s;
    cin >> s;
    cout << (isP(s) ? "YES" : "NO") << endl; 
    return 0;
}
