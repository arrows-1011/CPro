#include <iostream>
#include <algorithm>
using namespace std;
 
string change(int n){
    string s = "";
    while(n > 0){
	s += (n % 10 + '0');
	n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
 
int main(){
    int n;
 
    while(cin >> n ,n){
	string str;
	cin >> str;
 
	while(n--){
	    string tmp = "";
	    int cnt = 1;
	    char key = str[0];
	    int size = str.size();
	    str[size] = '#';
	    for(int i = 1 ; i <= size ; i++){
		if(key == str[i]){
		    cnt++;
		}
		else{
		    tmp += change(cnt);
		    tmp += key;
		    key = str[i];
		    cnt = 1;
		}
	    }
       
	    str = tmp;
	}
	cout << str << endl;
    }
    return 0;
}
