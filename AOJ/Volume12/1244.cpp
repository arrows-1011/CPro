#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 1e9
 
int idx,size;
bool found;
map<string,int> mp;
 
int getNum(const string &s){
    int res = 0, w = 1;
    string str;
    while(isdigit(s[idx])){
	str += s[idx];
	idx++;
    }
    for(int i = str.size()-1 ; i >= 0 ; i--){
	res += (str[i]-'0')*w;
	w *= 10;
    }
    return res;
}
 
int parse(const string &s){
    if(idx >= size) return 0;
    int num = 1;
    if(s[idx] == '('){
	idx++;
	int n = parse(s),a = 0;
	idx++;
	if(idx < size){
	    if(isdigit(s[idx])){
		num = getNum(s);
	    }
	}
	if(idx < size && s[idx] != ')'){
	    a = parse(s);
	}
	return n*num + a;
    }else if(isalpha(s[idx])){
	int res = 0;
	string str;
	while(idx < size && isalpha(s[idx])){
	    int f = -1;
	    str += s[idx++];
	    if(idx < size && !islower(s[idx])){
		if(mp.find(str) != mp.end()){
		    f = mp[str];
		    str = "";
		}else{
		    found = false;
		}
	    }
	    if(f != -1 && idx < size && isdigit(s[idx])){
		f *= getNum(s);
	    }
	    if(f != -1) res += f;
	}
	if(!str.empty()){
	    int f = -1;
	    if(mp.find(str) != mp.end()){
		f = mp[str];
	    }else{
		found = false;
	    }
	    if(f != -1 && idx + 1 < size && isdigit(s[idx+1])){
		idx++;
		f *= getNum(s);
	    }
	    if(f != -1) res += f;
	}
	if(!found) return -1;
	int a = 0;
	if(idx < size && s[idx] != ')'){
	    a = parse(s);
	}
	return res + a;
    }
}
 
int main(){
    string s;
    int num;
    while(cin >> s, s != "END_OF_FIRST_PART"){
	cin >> num;
	mp[s] = num;
    }
    while(cin >> s, s != "0"){
	idx = 0;
	found = true;
	size = s.size();
	int ans = parse(s);
	if(found){
	    cout << ans << endl;
	}else{
	    cout << "UNKNOWN" << endl;
	}
    }
    return 0;
}
