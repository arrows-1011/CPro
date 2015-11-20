#include <bits/stdc++.h>
 
using namespace std;
 
struct P{
    string a,b,c;
    P(){}
    P(string &a,string &b,string &c) : a(a),b(b),c(c) {}
};
 
vector<P> rules,ans;
map<string,bool> mp;
 
bool check(P p){
    for(int i = 0 ; i < (int)rules.size() ; i++){
	P rule = rules[i];
	bool flg = false;
	for(int j = 0 ; j < 8 ; j++){
	    if((rule.b[j] != '?' && rule.b[j] != p.a[j]) ||
	       (rule.c[j] != '?' && rule.c[j] != p.b[j])){
		flg = true;
		break;
	    }
	}
	if(!flg) return mp[rule.a];
    }
    return false;
}
 
int main(){
    int N,M;
    mp["permit"] = true;
    mp["deny"] = false;
    while(cin >> N >> M, (N|M)){
	P in;
	rules.clear(); ans.clear();
	while(N--){
	    cin >> in.a >> in.b >> in.c;
	    rules.push_back(in);
	}
	reverse(rules.begin(),rules.end());
	while(M--){
	    cin >> in.a >> in.b >> in.c;
	    if(check(in)){
		ans.push_back(in);
	    }
	}
	int s = ans.size();
	cout << s << endl;
	for(int i = 0 ; i < s ; i++){
	    cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
	}
    }
    return 0;
}
