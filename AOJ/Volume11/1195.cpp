#include <bits/stdc++.h>
 
using namespace std;
 
int len;
string str;
set<string> st;
 
void solve(int idx,string s,int S){
    if(idx == len){
	st.insert(s);
	return;
    }
    for(char ch = 'a' ; ch <= 'z' ; ch++){
	string next = s;
	int num = ch - 'a';
	next += ch;
	if(ch == 'a' || ((S >> num) & 1)){
	    if(ch == str[idx]){
		solve(idx+1,next,S);
	    }
	}else if(!((S >> num) & 1)){
	    if(ch-1 == str[idx]){
		solve(idx+1,next,S|(1<<num));
	    }else if(ch != 'z' && ((S >> (1+num)) & 1) && 
		     ch == str[idx] && ((S >> num) & 1)){
		solve(idx+1,next,S);
	    }
	}
    }
}
 
int main(){
    while(cin >> str, str != "#"){
	len = str.size();
	st.clear();
	solve(0,"",0);
	set<string>::iterator it;
	len = st.size();
	cout << len << endl;
	if(len <= 10){
	    for(it = st.begin() ; it != st.end() ; ++it){
		cout << *it << endl;
	    }
	}else{
	    vector<string> vec;
	    for(it = st.begin() ; it != st.end() ; ++it){
		vec.push_back(*it);
	    }
	    for(int i = 0 ; i < 5 ; i++){
		cout << vec[i] << endl;
	    }
	    for(int i = len-5 ; i < len ; i++){
		cout << vec[i] << endl;
	    }
	}
    }
    return 0;
}
