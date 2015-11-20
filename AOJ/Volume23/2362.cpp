#include <bits/stdc++.h>
 
using namespace std;
 
struct P{
    int a,b;
    string c;
   
    P(int a,int b,string c) : a(a),b(b),c(c) {}
    bool operator < (const P &p)const{
	if(a != p.a){
	    return a > p.a;
	}else{
	    return b < p.b;
	}
    }
};
 
int main(){
    string str,s;
    map<string,string> mp;
    mp["e"] = "egg";
    mp["c"] = "chicken";
    cin >> str;
    for(int i = 0 ; i < (int)str.size() ; i++){
	if(str[i] == 'e'){
	    i += 2;
	    s += 'e';
	}else{
	    i += 6;
	    s += 'c';
	}
    }
    int size = s.size();
    if(size == 1){
	cout << mp[s] << endl;
    }else{
	vector<P> vec;
	string tmp; tmp += s[0];
	for(int i = 1 ; i < size ; i++){
	    if(s[i-1] == s[i]){
		vec.push_back(P(tmp.size(),i,tmp));
		tmp = "";
	    }
	    tmp += s[i];
	}
	if(!tmp.empty()){
	    vec.push_back(P(tmp.size(),size,tmp));
	    tmp = "";
	}
	sort(vec.begin(),vec.end());
	tmp += vec[0].c[vec[0].c.size()-1];
	cout << mp[tmp] << endl;
    }
    return 0;
}
