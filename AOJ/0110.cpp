#include <iostream>
#include <algorithm>
#include <string>
 
using namespace std;
 
void change(string &s,int num){
    int length = (int)s.size();
    char ch = num + '0';
 
    for(int i = 0 ; i < length ; i++){
	if(s[i] == 'X'){
	    s[i] = ch;
	}
    }
}
 
bool check(char ch,int size){
    if(ch == 'X' && size > 1) return true;
    return false;
}
 
char calc(char x,char y,char z,bool &C){
    int a = x - '0',b = y - '0',c = z - '0';
    int d = a + b + c;
    if(d >= 10){
	C = true;
	d -= 10;
    }
    return d + '0';
}
 
string sum(string a,string b){
    string res = "";
 
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
 
    int length;
    if((int)a.size() > (int)b.size()){
	length = (int)a.size();
     
	for(int i = (int)b.size() ; i < length ; i++){
	    b += '0';
	}
    }
    else{
	length = (int)b.size();
 
	for(int i = (int)a.size() ; i < length ; i++){
	    a += '0';
	}
    }
 
    for(int i = 0 ; i <= length ; i++){
	res += '0';
    }
 
    for(int i = 0 ; i < length ; i++){
	bool C = false;
	res[i] = calc(a[i],b[i],res[i],C);
	if(C) res[i+1] = ((res[i+1]-'0') + 1) + '0';
    }
 
    for(int i = length ; i > 0; i--){
	if(res[i] == '0'){
	    res.erase(res.begin()+i);
	}
	else{
	    break;
	}
    }
    reverse(res.begin(),res.end());  
    return res;
}
 
int main(){
    string str;
 
    while(cin >> str){
	int pos_plus = str.find('+'),pos_equal = str.find('=');    
 
	string x = str.substr(0,pos_plus);
	string y = str.substr(pos_plus+1,pos_equal-pos_plus-1);
	string z = str.substr(pos_equal + 1);
 
	int start = 0;
	if(check(x[0],x.size()) || 
	   check(y[0],y.size()) || 
	   check(z[0],z.size())) {
	    start = 1;
	}    
 
	int ans;
	bool found = false;
	for(int i = start ; i < 10 ; i++){
	    string a = x, b = y, c = z;
    
	    change(a,i); change(b,i); change(c,i);
 
	    if(sum(a,b) == c){
		found = true;
		ans = i;
		break;
	    }
	}
 
	if(found) cout << ans << endl;
	else cout << "NA" << endl;
    }
    return 0;
}
