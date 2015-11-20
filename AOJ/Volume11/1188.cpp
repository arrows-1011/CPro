#include <bits/stdc++.h>
 
using namespace std;
 
string s;
string::iterator it;
 
int solve(){
    int res = 0;
    ++it;
    if(*it == '['){
	vector<int> v;
	while(*it == '['){
	    v.push_back(solve());
	    ++it;
	}
	sort(v.begin(),v.end());
	for(int i = 0 ; i <= (int)v.size()/2 ; i++){
	    res += v[i];
	}
    }else{
	while(isdigit(*it)){
	    res *= 10;
	    res += (*it - '0');
	    ++it;
	}
	(res /= 2)++;
    }
    return res;
}
 
int main(){
    int N;
    cin >> N;
    while(N--){
	cin >> s;
	it = s.begin();
	cout << solve() << endl;
    }
    return 0;
}
