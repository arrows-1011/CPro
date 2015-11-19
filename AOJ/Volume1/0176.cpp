#include <iostream>
#include <cmath>
 
using namespace std;

#define INF (1<<29)

string str;
const string color[8] = {"black","blue","lime","aqua","red","fuchsia",
			 "yellow","white"};
const string strong[8] = {"#000000","#0000ff","#00ff00","#00ffff","#ff0000",
			  "#ff00ff","#ffff00","#ffffff"};
 
int change(char ch){
    if('0' <= ch && ch <= '9'){
	return ch - '0';
    }
    return 10 + (ch - 'a');
}
 
int d(string str1,string str2){
    int R1 = change(str1[1])*16 + change(str1[2]);
    int G1 = change(str1[3])*16 + change(str1[4]);
    int B1 = change(str1[5])*16 + change(str1[6]);
 
    int R2 = change(str2[1])*16 + change(str2[2]);
    int G2 = change(str2[3])*16 + change(str2[4]);
    int B2 = change(str2[5])*16 + change(str2[6]);
 
    int res = pow(R1-R2,2.0) + pow(G1-G2,2.0) + pow(B1-B2,2.0);
 
    return res;
}
 
int main(){
    while(cin >> str , str != "0"){
	int min_ = INF,ans;
	for(int i = 0 ; i < 8 ; i++){
	    int dist = d(str,strong[i]);
	    if(dist < min_){
		min_ = dist;
		ans = i;
	    }
	}
	cout << color[ans] << endl;
    }
    return 0;
}
