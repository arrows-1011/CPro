#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
string solve(ll x){
    string res;
    if(x == 0LL){ return "0"; }
    ll a,b;
    int t = 0;
    for(; x ; t++){
	t = t & 1;
	a = x / 10;
	b = x - a * 10;
	if(b < 0 && t == 0){
	    a--;
	    b += 10;
	}else if(b > 0 && t == 1){
	    a++;
	    b -= 10;
	}
	b = (b < 0 ? -b : b);
	res = " " + res;
	res[0] = b + '0';
	x = a;
    }
    return res;
}
 
int main(){
    ll x;
    while(cin >> x, x){
	cout << solve(x) << endl;
    }
    return 0;
}
