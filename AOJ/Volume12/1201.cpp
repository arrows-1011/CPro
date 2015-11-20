#include <bits/stdc++.h>
 
using namespace std;
 
string s[10],srev[10];
string H[5],W[5];
bool eq[10];
 
bool valid(int idx){
    for(int i = 0 ; i < 5 ; i++){
	if(W[idx][i] == H[i][idx]){
	    return false;
	}
    }
    return true;
}
 
int solve(int idx,int S){
    if(S == (1<<10)-1){
	return 1;
    }
    int res = 0;
    for(int i = 0 ; i < 10 ; i++){
	if((S >> i) & 1) continue;
	if(idx < 5){
	    H[idx] = s[i];
	    res += solve(idx+1,S|(1<<i));
	    if(!eq[i]){
		H[idx] = srev[i];
		res += solve(idx+1,S|(1<<i));
	    }
	}else{
	    W[idx-5] = s[i];
	    if(valid(idx-5)){
		res += solve(idx+1,S|(1<<i));
	    }
	    if(!eq[i]){
		W[idx-5] = srev[i];
		if(valid(idx-5)){
		    res += solve(idx+1,S|(1<<i));
		}
	    }
	}
    }
    return res;
}
 
int main(){ 
    while(cin >> s[0], s[0] != "END"){
	memset(eq,false,sizeof(eq));
	string tmp = s[0];
	reverse(tmp.begin(),tmp.end());
	srev[0] = tmp;
	eq[0] = s[0] == srev[0];
	for(int i = 0 ; i < 9 ; i++){
	    cin >> s[i+1];
	    tmp = s[i+1];
	    reverse(tmp.begin(),tmp.end());
	    srev[i+1] = tmp;
	    eq[i+1] = s[i+1] == srev[i+1];
	}
	cout << solve(0,0)/8 << endl;
    }
    return 0;
}
