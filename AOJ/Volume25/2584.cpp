#include <bits/stdc++.h>
 
using namespace std;
 
int idx,size;
string s;
 
string parse(){
    string res;
    if(idx >= size || s[idx] == ']') return res;
    if(isupper(s[idx])){
	while(idx < size && isupper(s[idx])){
	    res += s[idx++];
	}
    }else if(s[idx] == '['){
	idx++;
	string str = parse();
	idx++;
	reverse(str.begin(),str.end());
	res += str;
    }else if(s[idx] == '?'){
	res += 'A'; idx++;
    }else if(s[idx] == '+' || s[idx] == '-'){
	int p[85] = {0}, N = 0;
	while(idx < size && (s[idx] == '+' || s[idx] == '-')){
	    if(s[idx] == '+'){
		p[N++] = 1;
	    }else{
		p[N++] = -1;
	    }
	    idx++;
	}
	if(isupper(s[idx])){
	    int x = s[idx];
	    for(int i = 0 ; i < N ; i++){
		x += p[i];
		if(x > 'Z'){ x = 'A'; }
		else if(x < 'A'){ x = 'Z'; }
	    }
	    res += (char)x;
	}else if(s[idx] == '?'){
	    res += 'A';
	}
	idx++;
    }
    return res + parse();
}
 
int main(){
    while(cin >> s, s != "."){
	idx = 0; size = s.size();
	cout << parse() << endl;
    }
    return 0;
}
