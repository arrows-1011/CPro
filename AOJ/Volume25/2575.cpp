#include <iostream>
#include <algorithm>
  
using namespace std;
  
int main(){
    string s,ans = "";
  
    cin >> s;
    int len = (int)s.size();
    for(int i = 0 ; i < len ; i++){
	string str = "";
	for(int j = 0 ; j < 8 ; j++){
	    if(i + j > len) break;
	    str += s[i+j];
	}   
	sort(str.begin(),str.end());
	if(str == "AADINNUY"){
	    ans += "AIZUNYAN";
	    i += 7;
	}else{
	    ans += s[i];
	}
    }
    cout << ans << endl;
  
    return 0;
}
