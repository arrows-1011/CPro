#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string str,res;
    bool flg = false;
    cin >> str;
    for(auto x : str){
	if(flg){
	    if(x == 'Z'){
		flg = false;
		res += "AZ";
	    }
	}else{
	    if(x == 'A'){
		flg = true;
	    }
	}
    }
    if(res.empty()){
	cout << -1 << endl;
    }else{
	cout << res << endl;
    }
    return 0;
}
