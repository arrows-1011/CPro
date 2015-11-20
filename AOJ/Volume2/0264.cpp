#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
struct Calc{
    ll p;
    string s;
    string::iterator it;
 
    Calc(ll p,string s) : p(p), s(s) {
	it = s.begin();
    }
 
    ll add(ll a,ll b){
	return (a + b) % p;
    }
 
    ll sub(ll a,ll b){
	return (a - b + p) % p;
    }
 
    ll mul(ll a,ll b){
	return (a * b) % p;
    }
 
    ll extgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b != 0LL){
	    d = extgcd(b,a%b,y,x);
	    y -= (a/b)*x;
	}else{
	    x = 1LL;
	    y = 0LL;
	}
	return d;
    }
 
    ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m + x % m) % m;
    }
 
    ll fact(){
	ll res = 0LL;
	if(*it == '('){
	    ++it;
	    res = exp();
	    ++it;
	}else{
	    while(isdigit(*it)){
		res *= 10LL;
		res += (*it-'0');
		++it;
	    }
	}
	return res;
    }
 
    ll term(){
	ll res = fact();
	while(*it == '*' || *it == '/'){
	    if(*it == '*'){
		++it;
		res = mul(res,fact());
	    }else if(*it == '/'){
		++it;
		ll x = fact();
		if(x == 0LL){ throw 0; }
		res = mul(res,mod_inverse(x,p));
	    }
	}
	return res;
    }
 
    ll exp(){
	ll res = term();
	while(*it == '+' || *it == '-'){
	    if(*it == '+'){
		++it;
		res = add(res,term());
	    }else if(*it == '-'){
		++it;
		res = sub(res,term());
	    }
	}
	return res;
    }
};
 
string compress(string s){
    string res;
    for(int i = 0 ; i < (int)s.size() ; i++){
	if(s[i] != ' '){ res += s[i]; }
    }
    return res;
}
 
int main(){
    ll p;
    string in;
    while(getline(cin,in),in != "0:"){
	string s;
	int i;
	in = compress(in);
	for(i = 0 ; i < (int)in.size() ; i++){
	    if(in[i] == ':'){ break; }
	    s += in[i];
	}
	stringstream ss(s);
	ss >> p;
	in = in.substr(i+1); 
	Calc c(p,in);
	try{
	    ll res = c.exp();
	    cout << in << " = " << res << " (mod " << p << ")" << endl;
	}catch(...){
	    cout << "NG" << endl;
	}
    }
    return 0;
}
