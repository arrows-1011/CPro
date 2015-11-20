#include <iostream>
#include <algorithm>
#include <string>
  
using namespace std;
  
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
    int n;
    cin >> n;
    while(n--){
	string a,b;
	cin >> a >> b;
	string c = sum(a,b);
	if((int)c.size() > 80) cout << "overflow" << endl;
	else cout << c << endl;
    }
    return 0;
}
