#include <iostream>
 
using namespace std;
 
int main(){
    string s[3];
 
    while(cin >> s[0], s[0] != "0"){
	for(int i = 1 ; i < 3 ; i++){
	    cin >> s[i];
	}   
	bool end = false;
	for(int i = 0 ; i < 3 ; i++){
	    char ch = s[i][0];
	    bool ok = true;
	    for(int j = 1 ; j < 3 ; j++){
		if(s[i][j] != ch || s[i][j] == '+'){
		    ok = false;
		    break;
		}
	    }
	    if(ok){
		cout << ch << endl;
		end = true;
		break;
	    }
	}
 
	if(end){
	    continue;
	}  
 
	for(int i = 0 ; i < 3 ; i++){
	    char ch = s[0][i];
	    bool ok = true;
	    for(int j = 1 ; j < 3 ; j++){
		if(s[j][i] != ch || s[j][i] == '+'){
		    ok = false;
		    break;
		}
	    }
	    if(ok){
		cout << ch << endl;
		end = true;
		break;
	    }
	}
	if(end){
	    continue;
	}
 
	char ch = s[0][0];
	bool ok = true;
	for(int i = 1 ; i < 3 ; i++){
	    if(ch != s[i][i] || ch == '+'){
		ok = false;
		break;
	    }
	}
 
	if(ok){
	    cout << ch << endl;
	    continue;
	}
 
	ch = s[0][2];
	ok = true;
	for(int i = 1 ; i < 3 ; i++){
	    if(ch != s[i][2-i] || ch == '+'){
		ok = false;
		break;
	    }
	}
 
	if(ok){
	    cout << ch << endl;
	    continue;
	}
	cout << "NA" << endl;
    } 
    return 0;
}
