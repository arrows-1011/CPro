#include <bits/stdc++.h>
 
using namespace std;
 
string s;
typedef pair<int,string> P;
 
bool is_palindrome(const string &str){
    int size = str.size();
    for(int i = 0 ; i < size/2 ; i++){
	if(str[i] != str[size-i-1]) return false;
    }
    return true;
}
 
bool check(string a,string b){
    int alen = a.size(),blen = b.size();
    if(alen % 2 && blen % 2 == 0) return true;
    if(alen % 2 == 0 && blen % 2) return true;
    if(alen == blen) return true;
    if(alen > blen) swap(a,b),swap(alen,blen);
    int p = 0;
    while(true){
	if(p*2+alen == blen) break;
	p++;
    }
    for(int i = p ; i < p+alen ; i++){
	if(a[i-p] != b[i]) return true;
    }
    return false;
}
 
int main(){
    string in;
    while(getline(cin,in)){
	int size;
	set<P> st;
	set<string> ans;
	s.clear();
     
	for(int i = 0 ; i < (int)in.size() ; i++){
	    if(isalpha(in[i])){
		s += toupper(in[i]);
	    }
	}
	size = s.size();
	for(int i = 0 ; i < size ; i++){
	    for(int j = size ; j > i ; j--){
		string str = s.substr(i,j-i);
		if(is_palindrome(str) && j-i >= 3){
		    st.insert(P(str.size(),str));
		}
	    }
	}
	bool ok[1145] = {false};
	int ii,jj;
	set<P>::iterator i,j;
	for(ii = 0,i = st.begin() ; i != st.end() ; ++i,++ii){
	    for(jj = 0,j = st.begin() ; j != st.end() ; ++j,++jj){
		if(i == j) continue;
		if(!check(i->second,j->second)){
		    if(i->first > j->first){
			ok[jj] = true;
		    }else{
			ok[ii] = true;
		    }
		}
	    }
	}
	for(ii = 0,i = st.begin() ; i != st.end() ; ++i,++ii){
	    if(ok[ii]) continue;
	    ans.insert(i->second);
	}
	bool flg = false;
	set<string>::iterator k;
	for(k = ans.begin() ; k != ans.end() ; ++k){
	    if(flg) cout << " ";
	    flg = true;
	    cout << *k;
	}
	cout << endl;
    }
    return 0;
}
