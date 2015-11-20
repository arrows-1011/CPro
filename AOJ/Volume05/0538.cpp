#include <iostream>
#include <string>

using namespace std;
 
int main(){
    int n,len;
    string str;
 
    while(cin >> n,n){
	string key = "I";
	for(int i = 0 ; i < n ; i++){
	    key += "OI";
	}
 
	int cnt = 0;
	cin >> len >> str;
	for(int i = 0 ; i < len ; i++){
	    string search = str.substr(i,key.size());
	    if(search == key) cnt++;
	}
	cout << cnt << endl;
    }
    return 0;
}
