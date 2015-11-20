#include <iostream>

using namespace std;
 
char g[10] = {'w','a','k','s','t','n','h','m','y','r'};
char t[5] = {'a','i','u','e','o'};
 
string change(string key){
    string s = "";
    if(key[0]=='0'&&key[1]=='U') s += "nn";
 
    else{
	if(g[key[0]-'0']!='a') s += g[key[0]-'0'];
     
	switch(key[1]){
	case 'T':
	    s += t[0];
	    break;
	case 'L':
	    s += t[1];
	    break;
	case 'U':
	    s += t[2];
	    break;
	case 'R':
	    s += t[3];
	    break;
	case 'D':
	    s += t[4];
	    break;
	}
    }
   
    return s;
}
 
int main(){
    string str,ans;
 
    ans = "";
 
    cin >> str;
    for(int i = 0 ; i < str.length() ; i++){
	string key = str.substr(i,2);
	if(i%2==0){
	    ans += change(key);
	}
    }
    cout << ans << endl;
 
    return 0;
}
