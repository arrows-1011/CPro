#include <iostream>
#include <algorithm>
using namespace std;
 
string str;
char c[128];
 
void c2c(){
    c['['] = ']';
    c['('] = ')';
    c['{'] = '}';
    c[']'] = '[';
    c[')'] = '(';
    c['}'] = '{';
}
 
int solve(string left,string right){
    int cnt = 0;
    c2c();
 
    for(int i = 0 ; i < (1 << left.length()) ; i++){
	string nleft = "";
	for(int j = 0 ; j < left.length() ; j++){
	    if(i >> j & 1){
		nleft += left[j];
	    }
	}
	for(int j = 0 ; j < (1 << right.length()) ; j++){
	    string nright = "";
	    for(int k = 0 ; k < right.length() ; k++){
		if(j >> k & 1){
		    nright += c[right[k]];
		}
	    }
	    if(nright.length() != nleft.length()){
		continue;
	    } 
	    int t = 0;
	    for(int j = 0 ; j < nleft.length() ; j++){
		if(nleft[j] != nright[nleft.length()-j-1]) break;
		++t; 
	    }
	    cnt = max(cnt,t);     
	}  
    }
    return 2*cnt+3;
}
 
int main(){
    cin >> str;
 
    string left = "" , right = "";
    int length = str.length();
 
    int i;
    for(i = 0 ; i < length ; i++){
	if(str[i] == 'i') break;
	left += str[i];
    }
    i += 2;
    for(int j = i ; j < length ; j++){
	right += str[j];
    }
    cout << solve(left,right) << endl;
    return 0;
}
