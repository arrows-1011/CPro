#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define A cout << "Audrey wins." << endl
#define F cout << "Fabre wins." << endl
 
int c2i(char s){
    return s-'0';
}
 
string c2s(char aa,char bb){
    int a = c2i(aa)+c2i(bb);
    if(a == 0) return "0";
 
    string s = "";
    while(a > 0){
	s += ((a%10)+'0');
	a /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}
 
int main(){
    int n;
 
    cin >> n;
    while(n--){
	string str;
	cin >> str;
     
	int cnt = 0;
	while(str.size() >= 2){
	    cnt++;
	    int pos = str.size()-2;
	    string tmp = c2s(str[pos],str[pos+1]);
	    if(pos >= 0) str = str.substr(0,pos) + tmp;
	}
	if(cnt%2) F;
	else A;    
    }
    return 0;
}
