#include <bits/stdc++.h>

using namespace std;

class calc{
    string s;
    string::iterator it;
 
public:
    calc(const string &str){
	s = str;
	it = s.begin();
    }
 
    int fact(){
	if(*it == '('){
	    ++it;
	    int ret = exp();
	    ++it;
	    return ret;
	}
	else{
	    int ret = 0;
	    while('0' <= *it && *it <= '9'){
		ret *= 10;
		ret += *it - '0';
		++it;
	    }
	    return ret;
	}
    }
 
    int term(){
	int ret = fact();
	while(*it == '*' || *it == '/'){
	    if(*it == '*'){
		++it;
		ret *= fact();
	    }
	    else if(*it == '/'){
		++it;
		ret /= fact();
	    }
	}
	return ret;
    }
   
    int exp(){
	int ret = term();
 
	while(*it == '+' || *it == '-'){
	    if(*it == '+'){
		++it;
		ret += term();
	    }
	    else if(*it == '-'){
		++it;
		ret -= term();
	    }
	}
	return ret;
    }
};
 
