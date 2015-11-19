#include <iostream>
#include <string>
#include <cstdio>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    while(n--){
	string snake;
	cin >> snake;
 
	string s = snake.substr(0,2);
 
	if(s != ">^" && s != ">\'"){
	    puts("NA");
	    continue;
	}
 
	if(s == ">\'"){
	    int a = 0;
	    int p = 2;
	    bool flg = true;
	    int len = (int)snake.size();
	    for(int i = 2 ; i < len ; i++,p++){
		if(snake[i] == '#') break;
		else if(snake[i] == '=') a++;
		else{
		    flg = false;
		    break;
		}
	    }
 
	    if(!flg){
		puts("NA");
		continue;
	    }      
 
	    int b = 0,q = p + 1;
	    for(int i = q ; i < len ; i++,p++){
		if(snake[i] == '~') break;
		else if(snake[i] == '=') b++;
		else{
		    flg = false;
		    break;
		}
	    }
 
	    if(!flg || a == 0 || b == 0 || a != b){
		puts("NA");
		continue;
	    }  
 
	    if(a == b && snake[len-1] == '~'){
		puts("A");
	    }else{
		puts("NA");
	    }
	}else{
	    bool ok = true;
	    int p = 0;
	    string ss = "";
	    int len = (int)snake.size();
 
	    if(len < 6 || len % 2){
		puts("NA");
		continue;
	    } 
 
	    for(int i = 2 ; i < len-2 ; i++,p++){
		ss += snake[i];
		if(p == 1){
		    p = -1;
		    if(ss != "Q="){
			ok = false;
			break;
		    }
		    ss = "";
		}
	    }
 
	    if(snake[len-2] == '~' && snake[len-1] == '~' && ok){
		puts("B");
	    }else{
		puts("NA");
	    }
	}
    }
    return 0;
}
