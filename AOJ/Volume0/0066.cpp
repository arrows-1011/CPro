#include <iostream>
#include <string>

using namespace std;
 
int main(){
    string str;
    while(getline(cin,str)){
	char mp[3][3];
	int d = 0;
 
	for(int i = 0 ; i < 3 ; i++){
	    for(int j = 0 ; j < 3 ; j++){
		mp[i][j] = str[d++];
	    }
	}
 
	int flg = 0;
  
	for(int i = 0 ; i < 3 ; i++){
	    int m = 0 , b = 0;
	    for(int j = 0 ; j < 3 ; j++){
		if(mp[i][j]=='o') m++;
		else if(mp[i][j]=='x')b++;
	    } 
	    if(m==3){
		cout << 'o' << endl;
		flg = 1;
		break;
	    }
	    if(b==3){
		cout << 'x' << endl;
		flg = 1;
		break;
	    }
	}
	if(flg) continue;
 
	for(int j = 0 ; j < 3 ; j++){
	    int m = 0, b = 0;
	    for(int i = 0 ; i < 3 ; i++){
		if(mp[i][j]=='o') m++;
		else if(mp[i][j]=='x') b++;   
	    }
	    if(m==3){
		cout << 'o' << endl;
		flg = 1;
		break;
	    }
	    if(b==3){
		cout << 'x' << endl;
		flg = 1;
		break;
	    }
	}
	if(flg) continue;
 
	if(mp[1][1]=='o'){
	    if((mp[0][0]==mp[1][1]&&mp[1][1]==mp[2][2])||
	       (mp[0][2]==mp[1][1]&&mp[1][1]==mp[2][0])){
		cout << 'o' << endl;
		flg = 1;
	    }
	}
	if(mp[1][1]=='x'){
	    if((mp[0][0]==mp[1][1]&&mp[1][1]==mp[2][2])||
	       (mp[0][2]==mp[1][1]&&mp[1][1]==mp[2][0])){
		cout << 'x' << endl;
		flg = 1;
	    }
	}
	if(flg) continue;
 
	cout << 'd' << endl;
    }
    return 0;
}
