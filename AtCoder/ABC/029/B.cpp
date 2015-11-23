#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int res = 0;
    for(int i = 0 ; i < 12 ; i++){
	string s; cin >> s;
	bool ok = false;
	for(int j = 0 ; j < s.size() ; j++){
	    if(s[j] == 'r'){
		ok = true;
		break;
	    }
	}
	res += ok;
    }
    cout << res << endl;
    return 0;
}
