#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX 201
typedef pair<string,string> P;
 
int N,D,idx;
string s[MAX];
map<int,set<string> > mp;
vector<P> vec;
 
void dfs(string now,int step){
    if(step == 1){
	mp[idx].insert(now);
	return;
    }
   
    int len = now.size();
    // delete
    for(int i = 0 ; i < len ; i++){
	string tmp = now;
	tmp.erase(tmp.begin()+i);
	dfs(tmp,step+1);
    }
  
    // swap
    for(int i = 0 ; i < len-1 ; i++){
	swap(now[i],now[i+1]);
	dfs(now,step+1);
	swap(now[i],now[i+1]);
    }
 
    // insert
    for(char ch = 'a' ; ch <= 'z' ; ch++){
	for(int j = 0 ; j < len+1 ; j++){
	    string tmp = now;
	    tmp = tmp.substr(0,j) + ch + tmp.substr(j);
	    dfs(tmp,step+1);
	}
    }
  
    // replace
    for(char ch = 'a' ; ch <= 'z' ; ch++){
	for(int j = 0 ; j < len ; j++){
	    char c = now[j];
	    now[j] = ch;
	    dfs(now,step+1);
	    now[j] = c;
	}
    }
}
 
void init(){
    mp.clear();
    vec.clear();
}
 
int main(){
    while(cin >> N, N){
	cin >> D;
	init();
	for(int i = 0 ; i < N ; i++){
	    cin >> s[i];
	}
	for(int i = 0 ; i < N ; i++){
	    idx = i;
	    dfs(s[i],0);
	}
 
	vector<string> v[MAX];
	for(int i = 0 ; i < N ; i++){
	    set<string> st = mp[i];
	    set<string>::iterator it;
	    for(it = st.begin() ; it != st.end() ; ++it){
		v[i].push_back(*it);
	    }
	} 
 
	if(D == 1){
	    for(int i = 0 ; i < N ; i++){
		unordered_map<string,bool> ump;
		for(int j = 0 ; j < (int)v[i].size() ; j++){
		    ump[v[i][j]] = true;
		}
		for(int j = i+1 ; j < N ; j++){
		    if(ump.find(s[j]) != ump.end()){
			vec.push_back(P(s[i],s[j]));
		    }
		}
	    }
	}else{
	    for(int i = 0 ; i < N ; i++){
		unordered_map<string,bool> ump;
		for(int j = 0 ; j < (int)v[i].size() ; j++){
		    ump[v[i][j]] = true;
		}
		for(int j = i+1 ; j < N ; j++){
		    for(int k = 0 ; k < (int)v[j].size() ; k++){
			if(ump.find(v[j][k]) != ump.end()){
			    vec.push_back(P(s[i],s[j]));
			    break;
			}
		    }
		}
	    }
	}
	int len = vec.size();
	for(int i = 0 ; i < len ; i++){
	    if(vec[i].first > vec[i].second){
		swap(vec[i].first,vec[i].second);
	    }
	}
	sort(vec.begin(),vec.end());
	for(int i = 0 ; i < len ; i++){
	    cout << vec[i].first << "," << vec[i].second << endl;
	}
	cout << len << endl;
    }
    return 0;
}
