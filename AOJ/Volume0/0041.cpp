#include <iostream>
#include <algorithm>
#include <cstdio>
 
using namespace std;

#define rep(i,n) for(int i = 0 ; i < n ; i++)

int a[4];
 
int calc(int a,char c,int b){
    if(c == '+'){
	return a + b;
    } else if(c == '-'){
	return a - b;
    }
    return a * b;
}
 
bool t(int res){
    if(res == 10){
	return true;
    }
    return false;
}
 
string op = "+-*";
 
void solve(bool &found){
    rep(i,3) rep(j,3) rep(k,3){
	if(t(calc(calc(a[0],op[i],calc(a[1],op[j],a[2])),op[k],a[3]))){
	    printf("((%d %c (%d %c %d)) %c %d)\n"
		   ,a[0],op[i],a[1],op[j],a[2],op[k],a[3]);
 
	    found = true;
	    return;
	} 
	if(t(calc(calc(a[0],op[i],calc(a[1],op[j],a[2])),op[k],a[3]))){
	    printf("(%d %c (%d %c %d) %c %d)\n"
		   ,a[0],op[i],a[1],op[j],a[2],op[k],a[3]);
 
	    found = true;
	    return;
	} 
	if(t(calc(calc(a[0],op[i],a[1]),op[j],calc(a[2],op[k],a[3])))){
	    printf("((%d %c %d) %c (%d %c %d))\n"
		   ,a[0],op[i],a[1],op[j],a[2],op[k],a[3]);
 
	    found = true;
	    return;
	}
    }
 
}
 
int main(){
    while(true){
	rep(i,4){
	    cin >> a[i]; 
	}
 
	if(a[0] == 0) break;
	sort(a,a+4);
 
	bool found = false;
 
	do{
	    found = false;
	    solve(found);
	    if(found) break;
	}while(next_permutation(a,a+4));    
 
	if(!found){
	    cout << "0" << endl;
	}
    }
    return 0;
}
