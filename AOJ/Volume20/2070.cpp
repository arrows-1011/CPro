#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 300
#define INF (1<<29)
typedef long long ll;
 
bool ok(int x){
    return (0 <= x && x < 10000);
}
 
ll getNum(int *idx,string &str){
    ll res = 0;
    while(isdigit(str[*idx])){
	res *= 10;
	res += str[*idx]-'0';
	(*idx)++;
    }
    return res;
}
 
ll calc(int idx,string &str){
    ll num,num2;
    if(str[idx] == '-'){
	idx++;
	num = -getNum(&idx,str);
	if(!ok(num)) return INF;
    }else if(str[idx] == '+'){
	idx++;
	num = getNum(&idx,str);
	if(!ok(num)) return INF;
    }else{
	num = getNum(&idx,str);
	if(!ok(num)) return INF;
    }
    while(str[idx] != '='){
	switch(str[idx]){
	case '+':
	    idx++;
	    num2 = getNum(&idx,str);
	    if(!ok(num2)) return INF;
	    num += num2;
	    break;
	case '-':
	    idx++;
	    num2 = getNum(&idx,str);
	    if(!ok(num2)) return INF;
	    num -= num2;
	    break;
	case '*':
	    idx++;
	    num2 = getNum(&idx,str);
	    if(!ok(num2)) return INF;
	    num *= num2;
	    break;
	}
	if(!ok(num)) return INF; 
    }
    if(!ok(num)) return INF;
    return num;
}
 
int main(){
    string str;
    while(cin >> str){
	string nstr;
	int len = str.size();
	for(int i = 0 ; i < len-1 ; i++){
	    nstr += str[i];
	    if(!isdigit(str[i]) && !isdigit(str[i+1])){
		nstr += '0';
	    }
	}
	nstr += '=';
	int res = calc(0,nstr);
	if(res == INF){
	    cout << "E" << endl;
	}else{
	    cout << res << endl;
	}
    }
    return 0;
}
