#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string s,t;
    getline(cin,s);
    stringstream ss(s);
    bool f = false;
    while(ss >> t){
	if(f) cout << " ";
	f = true;
	if(t == "Left"){
	    cout << "<";
	}else if(t == "Right"){
	    cout << ">";
	}else{
	    cout << "A";
	}
    }
    cout << endl;
    return 0;
}
