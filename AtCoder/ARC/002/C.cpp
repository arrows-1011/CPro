#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s[16] = {"AA","AB","AX","AY",
		    "BA","BB","BX","BY",
		    "XA","XB","XX","XY",
		    "YA","YB","YX","YY"};
    int N,res,len;
    string str; 
    cin >> N >> str; res = N; len = str.size();
    for(int L = 0 ; L < 16 ; L++){
	for(int R = L+1 ; R < 16 ; R++){
	    int sum = 0;
	    string t;
	    for(int j = 0 ; j < len ; j++){
		t += str[j];
		if(t.size() == 2){
		    if(s[L] == t || s[R] == t){
			t.clear();
			sum++;
		    }else{
			t = t[1];
			sum++;
		    }
		}
	    }
	    if(t.size() > 0) sum++;
	    res = min(res,sum);
	}
    }
    cout << res << endl;
    return 0;
}
