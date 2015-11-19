#include <iostream>
#include <string>

using namespace std;
 
int check(char a,char b){
    if(a == b) return 1;
    return 0;
}
 
int main(void){
    string str;
    int cnt = 0;
 
    while(cin >> str){
	int flg = 0;
	for(int i = 0 ; i < str.size()/2 ; i++){
	    if(!check(str[i],str[str.size()-i-1])){
		flg = 1;
		break;
	    }
	}
	if(flg == 0) cnt++;
    }
    cout << cnt << endl; 
    return 0;
}
