#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100
 
char data[MAX][MAX/2][MAX];
int plen, cnum, width, cspace, page;
int x, y;
string ss;
 
void init(){
    page = 0;
    for(int i = 0 ; i < MAX ; i++){
	for(int j = 0 ; j < MAX/2 ; j++){
	    for(int k = 0 ; k < MAX ; k++){
		data[i][j][k] = '.';
	    }
	}
    }
}
 
bool check(){
    bool ok = true;
    if(ss.empty()) return ok;
 
    for(int i = 0 ; i < plen ; i++){
	for(int j = 0 ; j < cnum*width+cspace*(cnum-1) ; j++){
	    if(data[i][j][page] != '.') return ok;
	}
    }
    return !ok;
}
 
void change(){
    y++;
    if(y == plen){
	y = 0;
	x++;
	if(x == cnum){
	    x = y = 0;
	    page++;
	}
    }
}
 
void insert(string &str){
    int size = str.size(), start;
    int end, p = 0;
    bool flg = true;
 
    while(flg){
	start = x*(width+cspace);
	if(size - p <= width){
	    end = start + size - p;
	    flg = false;
	}else{
	    flg = true;
	    end = start + width;
	}
	for(int i = start ; i < end ; i++, p++){
	    if(p == size){ 
		flg = false;
		break;
	    }
	    data[y][i][page] = str[p];
	}
	change(); 
    }
}
 
void print(){
    if(!check()) page--;
    for(int k = 0 ; k <= page ; k++){
	for(int i = 0 ; i < plen ; i++){
	    for(int j = 0 ; j < cnum*width+cspace*(cnum-1) ; j++){
		cout << data[i][j][k];
	    }
	    cout << endl;
	}
	cout << '#' << endl;
    }
    cout << '?' << endl;
}
 
int main(){
    string str;
    while(cin >> plen && plen){
	init();
	cin >> cnum >> width >> cspace;
 
	cin.ignore();
	x = y = 0;
	while(getline(cin,str), str != "?"){
	    ss = str;
	    if(str.empty()){
		change();
	    }else{
		insert(str);
	    }
	}
	print();
    }
    return 0;
}
