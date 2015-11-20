#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_L 1010
typedef pair<char,int> P;
 
int L,limit[52],v;
string line[MAX_L];
map<P,int> val;
 
int change(char x){
    if(islower(x)){
	return x-'a';
    }
    return x-'A'+26;
}
 
int getDigit(int *l,int *cur){
    int res = 0;
    while(isdigit(line[*l][*cur])){
	res *= 10;
	res += line[*l][*cur]-'0';
	(*cur)++;
    }
    return res;
}
 
int getArray(int *l,int *cur){
    char x = line[*l][*cur];
    int idx = change(x);
    (*cur) += 2;
    int num;
    if(islower(line[*l][*cur]) || isupper(line[*l][*cur])){
	num = v = getArray(l,cur);
	if(num == -1){ return -1; }
	if(limit[idx] <= num){
	    return -1;
	}
	(*cur)++;
	P p = P(x,num);
	if(val.find(p) == val.end()){
	    return -1;
	}else{
	    return val[P(x,num)];
	}
    }
    num = v = getDigit(l,cur);
    (*cur)++;
    if(limit[idx] <= num){ return -1; }
    else{
	P p = P(x,num);
	if(val.find(p) == val.end()){
	    return -1;
	}else{
	    return val[P(x,num)];
	}
    }
}
 
int solve(int l,int cur){
    if(l == L){ return 0; }
    char now = line[l][cur];
    if(islower(now) || isupper(now)){
	char x = line[l][cur];
	int num;
	getArray(&l,&cur);
	int v2 = v;
	if(line[l][cur] == '='){
	    cur++;
	    if(isdigit(line[l][cur])){
		num = getDigit(&l,&cur);
	    }else{
		num = getArray(&l,&cur);
		if(num == -1){ return l+1; }
	    }
	    if(limit[change(x)] <= v2){ return l+1; }
	    val[P(x,v2)] = num;
	    return solve(l+1,0);
	}else if(line[l][cur] == '$'){
	    limit[change(x)] = v;
	    return solve(l+1,0);
	}
    }
    return l+1;
}
 
void init(){
    val.clear();
    memset(limit,-1,sizeof(limit));
}
 
int main(){
    while(cin >> line[0],line[0] != "."){
	init();
	line[0] += '$';
	L = 1;
	while(true){
	    cin >> line[L];
	    if(line[L] == "."){ break; }
	    line[L] += '$';
	    L++;
	}
	cout << solve(0,0) << endl;
    }
    return 0;
}
