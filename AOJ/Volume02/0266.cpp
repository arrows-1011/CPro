#include <iostream>
 
using namespace std;
 
int next(int now,int num){
    switch(now){
    case 0:
	return num ? 4 : 3;
    case 1:
	return num ? 3 : 4;
    case 2:
	return num ? 4 : 1;
    case 3:
	return num ? 5 : -1;
    case 4:
	return num ? -1 : 3;
    case 5:
	return num ? 1 : 2;
    }
    return -1;
}
 
int main(){
    string str;
 
    while(cin >> str ,str != "#"){
	int now = 0; 
	for(int i = 0 ; i < (int)str.size() ; i++){
	    now = next(now,str[i]-'0');
	    if(now == -1) break;
	}
 
	if(now == 1){
	    cout << "Yes" << endl;
	}
	else{
	    cout << "No" << endl;
	}
    }
    return 0;
}
