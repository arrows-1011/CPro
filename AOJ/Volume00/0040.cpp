#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std; 
 
map<char,int> c_i;
map<int,char> i_c;
string str;
 
void init(){
    for(char ch = 'a' ; ch <= 'z' ; ch++){
	c_i[ch] = ch - 'a';
	i_c[ch-'a'] = ch;
    }
}
 
bool serch(string s){
    int a = s.find("that");
    int b = s.find("this");
 
    if(a != string::npos || b != string::npos) return true;
    return false;
}
 
char change(char ch,int a,int b){
    int num = c_i[ch];
    int nnum = (a*num+b) % 26;
 
    return i_c[nnum];
}
 
int main(){
    int n;
    init();
 
    cin >> n;
    cin.ignore();
 
    while(n--){
	getline(cin,str);
 
	for(int i = 0 ; i < 26 ; i++){
	    for(int j = 0 ; j < 26 ; j++){
		string tmp = "";
		for(int k = 0 ; k < str.size() ; k++){
		    if(islower(str[k])){
			tmp += change(str[k],i,j);
		    }
		    else tmp += str[k];
		}
		if(serch(tmp)){
		    cout << tmp << endl;
		    goto end;
		}
	    }
	}
    end:;
    }
 
    return 0;
}
