#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 26
 
bool data[MAX][MAX];
bool used[MAX];
vector<char> ans;
set<int> st;
 
bool cyc(int now, int cnt){
    if(cnt == 1){
	return true;
    }
    set<int>::iterator it;
    for(it = st.begin() ; it != st.end() ; ++it){
	int next = (*it) - 'a';
	ans.push_back((char)(*it));
	if(data[now][next] && cyc(next, cnt-1)){
	    return true;
	}
	ans.pop_back();
    }
    return false;
}
 
int main(){
    int n;
    string str;
 
    cin >> n;
    while(n--){
	memset(data,false,sizeof(data));
	st.clear();
 
	cin >> str;
	string tmp;
	for(int i = 0 ; i < str.size() ; i++){
	    if(str[i] == '-') continue;
	    tmp += str[i];
	}
	str = tmp;
	st.insert(str[0]);
	for(int i = 2 ; i < str.size() ; i += 2){
	    if(str[i-1] == '<'){
		data[str[i]-'a'][str[i-2]-'a'] = true;
	    }else{
		data[str[i-2]-'a'][str[i]-'a'] = true;
	    }
	    if(!st.count(str[i])){
		st.insert(str[i]);
	    }
	}
 
	int size = st.size();
	set<int>::iterator it;
	for(it = st.begin() ; it != st.end() ; ++it){
	    ans.clear();
	    memset(used,false,sizeof(used));
	    ans.push_back((char)(*it));
    
	    if(cyc((*it)-'a', size)){
		break;
	    }
	}
 
	for(int i = 0 ; i < ans.size() ; i++){
	    cout << ans[i];
	}
	cout << endl;
    }
    return 0;
}
