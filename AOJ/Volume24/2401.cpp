#include <bits/stdc++.h>
 
using namespace std;
 
int idx,S;
 
bool parse(const string &s){
    if(idx == (int)s.size()) return true;
    idx++;
    bool l,r,res;
    switch(s[idx]){
    case 'T':
	return true;
    case 'F':
	return false;
    case '-':
	return !parse(s);
    case '(':
	l = parse(s);
	idx++;
	if(s[idx] == '+'){
	    r = parse(s);
	    res = l | r;
	}else if(s[idx] == '*'){
	    r = parse(s);
	    res = l & r; 
	}else{
	    idx++;
	    r = parse(s);
	    res = !l || (l && r);
	}
	idx++;
	return res;
    default:
	return ((S >> (s[idx]-'a')) & 1);
    }
}
 
bool solve(const string &s){
    int eq = s.find('=');
    string l = s.substr(0,eq);
    string r = s.substr(eq+1);
    for(S = 0 ; S < (1<<11) ; S++){
	idx = -1;
	bool ll = parse(l);
	idx = -1;
	if(ll != parse(r)){
	    return false;
	}
    }
    return true;
}
 
int main(){
    string s;
    while(cin >> s, s != "#"){
	cout << (solve(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
