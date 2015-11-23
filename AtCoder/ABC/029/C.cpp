#include <bits/stdc++.h>
 
using namespace std;
 
int N;
set<string> st;
 
void rec(int idx,string s){
    if(idx == N){
	st.insert(s);
	return;
    }
    for(int i = 0 ; i < 3 ; i++){
	rec(idx+1,s+(char)('a' + i));
    }
}
 
int main(){
    cin >> N;
    rec(0,"");
    for(auto x : st){
	cout << x << endl;
    }
    return 0;
}
