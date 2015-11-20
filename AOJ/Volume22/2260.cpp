#include <iostream>
#include <string>
using namespace std;
 
char c[128];
 
void init(){
    c['('] = ')';
    c[')'] = '(';
    c['i'] = 'i';
    c['w'] = 'w';
    c[' '] = ' ';
}
 
int main(){
    string str;
    int cnt = 0;
 
    init();
    cin >> str;
 
    if(str.size()%2==1){
	if(str[str.size()/2] != 'w' && str[str.size()/2] != 'i'){
	    cnt++;
	}
    }
 
    for(int i = 0 ; i < str.size()/2 ; i++){
	if(str[i] != c[str[str.size()-i-1]]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
