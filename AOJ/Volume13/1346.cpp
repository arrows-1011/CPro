#include <bits/stdc++.h>
 
using namespace std;
 
struct M{
    string s;
    string::iterator it;
 
    void init(const string &str){
	s = str;
	it = s.begin();
    }
 
    int fact(){
	int res = 0;
	while(isdigit(*it)){
	    res *= 10;
	    res += *it-'0';
	    ++it;
	}
	return res;
    }  
 
    int exp(){
	int res = term();
	while(*it == '+'){
	    ++it;
	    res += term();
 
	}
	return res;
    }
 
    int term(){
	int res = fact();
	while(*it == '*'){
	    ++it;
	    res *= fact();
	}
	return res;
    }
};
 
struct L{
    string s;
    string::iterator it;
 
    void init(const string &str){
	s = str;
	it = s.begin();
    }
 
    int fact(){
	int res = 0;
	while(isdigit(*it)){
	    res *= 10;
	    res += *it-'0';
	    ++it;
	}
	return res;
    }  
 
    int calc(){
	int res = fact();
	while(*it == '+' || *it == '*'){
	    if(*it == '+'){
		++it;
		res += exp();
	    }else{
		++it;
		res *= term();
	    }
	}
	return res;
    }
 
    int exp(){
	int res = fact();
	while(*it == '+'){
	    ++it;
	    res += fact();
	}
	return res;
    }
 
    int term(){
	int res = fact();
	while(*it == '*'){
	    ++it;
	    res *= fact();
	}
	return res;
    }
};
 
int main(){
    int ans;
    string s;
    cin >> s >> ans; 
    M m; m.init(s); 
    L l; l.init(s);
    int Mres = m.exp(), Lres = l.calc();
 
    if(Mres == ans && Lres != ans){
	cout << 'M' << endl;
    }else if(Mres != ans && Lres == ans){
	cout << 'L' << endl;
    }else if(Mres == ans && Lres == ans){
	cout << 'U' << endl;
    }else{
	cout << 'I' << endl;
    }
    return 0;
}
