#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
 
using namespace std;
typedef unsigned int ui;
 
int main(){
    int Q;
 
    double c[7];
    for(int i = 0 ; i < 7 ; i++){
	c[i] = pow(0.5,i+1);
    }
 
    cin >> Q;
    while(Q--){
	ui s;
 
	scanf("%x" ,&s);
	ui integer = (s & 0x7fffffff) >> 7;
	ui decimal = (s & 0x0000007f);
 
	double d = 0;
	for(int i = 0 ; i < 7 ; i++){
	    if((1 << i) & decimal)
		d += c[6-i];
	}    
 
	char str[10];
	sprintf(str,"%.7f" ,d);
 
	int pos = -1;
	for(int i = 8 ; i >= 0 ; i--){
	    if(str[i] != '0' && str[i] != '.'){
		pos = i;
		break;
	    }
	}
 
	if((s >> 31) & 1) cout << '-';
	cout << integer << '.';
     
	if(pos == -1) cout << '0' << endl;
	else{
	    for(int i = 2 ; i <= pos ; i++){
		cout << str[i];
	    }
	    cout << endl;
	}
    }
    return 0;
}
