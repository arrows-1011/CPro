#include <iostream>
#include <cctype>
#include <vector>
 
using namespace std;
 
int len;
 
string UpperCamelCase(vector<string> v){
    string res = "";
 
    for(int i = 0 ; i < len ; i++){
	if(islower(v[i][0])){
	    v[i][0] = toupper(v[i][0]);
	}
	res += v[i];
    }
 
    return res;
}
 
string LowerCamelCase(vector<string> v){
    string res = v[0];
 
    for(int i = 1 ; i < len ; i++){
	if(islower(v[i][0])){
	    v[i][0] = toupper(v[i][0]);
	}
	res += v[i];
    }
 
    return res;
}
 
string Under(vector<string> v){
    string res = v[0];
 
    for(int i = 1 ; i < len ; i++){
	res += '_' + v[i];
    }
   
    return res;
}
 
int main(){
    string s;
    char order;
 
    while(cin >> s >> order, order != 'X'){
	if(isupper(s[0])){
	    s[0] = tolower(s[0]);
	}
	s += '_';
 
	vector<string> v;
	int pos = 0;
	len = (int)s.size();
 
	for(int i = 0 ; i < len ; i++){
	    if(isupper(s[i])){
		s[i] = tolower(s[i]);
		v.push_back(s.substr(pos,i-pos));
		pos = i;
	    }else if(s[i] == '_'){
		v.push_back(s.substr(pos,i-pos));
		pos = i + 1;
	    }
	}
 
	len = (int)v.size();
     
	if(order == 'U'){
	    cout << UpperCamelCase(v) << endl;
	}else if(order == 'L'){
	    cout << LowerCamelCase(v) << endl;
	}else{
	    cout << Under(v) << endl;
	}
    }
    return 0;
}
