#include <bits/stdc++.h>
 
using namespace std;
 
string s;
int size;
 
int getNum(int x){
    if(x == 1 || x == 4 || x == 7){
	return 0;
    }
    if(x == 2 || x == 8){
	return 1;
    }
    return 2;
}
 
bool valid(int left,int right){
    left = getNum(left);
    right = getNum(right);
    if(left > right){
	return false;
    }
    return true;
}
 
int solve(int foot){
    int left,right,cnt = 0;
    if(foot == 0){
	left = s[0]-'0';
	right = s[1]-'0';
    }else{
	left = s[1]-'0';
	right = s[0]-'0';
    }
    if(!valid(left,right)){
	return INT_MAX;
    }
    for(int i = 2 ; i < size ; i++){
	int next = s[i]-'0';
	if(foot == 0){
	    if(valid(next,right)){
		left = next;
		foot = 1-foot;
	    }else{
		right = next;
		cnt++;
	    }
	}else{
	    if(valid(left,next)){
		right = next;
		foot = 1-foot;
	    }else{
		left = next;
		cnt++;
	    }
	}
    }
    return cnt;
}
 
int main(){
    while(cin >> s, s != "#"){
	size = s.size();
	if(size <= 2){
	    puts("0");
	    continue;
	}
	cout << min(solve(0),solve(1)) << endl;
    }
    return 0;
}
