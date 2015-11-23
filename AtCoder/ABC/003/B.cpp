#include <bits/stdc++.h>
 
using namespace std;
 
bool check(char a,char b){
    if(a == '@'){ swap(a,b); }
    char cards[] = {'a','t','c','o','d','e','r'};
    for(auto x : cards){
	if(x == a){
	    return false;
	}
    }
    return true;
}
 
int main(){
    string S,T;
    cin >> S >> T;
    bool ok = true;
    for(int i = 0 ; i < (int)S.size() ; i++){
	if(S[i] == '@' && T[i] == '@') continue;
	if((S[i] == '@' && T[i] != '@') || (S[i] != '@' && T[i] == '@')){
	    if(check(S[i],T[i])){
		ok = false;
		break;
	    }
	    continue;
	}
	if(S[i] != T[i]){
	    ok = false;
	    break;
	}
    }
    cout << (ok ? "You can win" : "You will lose") << endl;
    return 0;
}
