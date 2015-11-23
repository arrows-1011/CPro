#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    char c[5] = {'a','i','u','e','o'};
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++){
	bool ok = true;
	for(int j = 0 ; j < 5 ; j++){
	    if(s[i] == c[j]){
		ok = false;
		break;
	    }
	}
	if(ok){
	    cout << s[i];
	}
    }
    cout << endl;
    return 0;
}
