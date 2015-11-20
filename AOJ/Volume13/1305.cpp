#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1500
 
vector<int> G[MAX];
set<int> st;
bool visited[MAX];
 
void solve(int v){
    if(st.count(v)) return;
    if(visited[v]) return;
    visited[v] = true;
    if(G[v].size() == 0){
	st.insert(v);
    }
    for(int i = 0 ; i < (int)G[v].size() ; i++){
	solve(G[v][i]);
    }
}
 
int main(){
    int N;
    while(cin >> N, N){
	for(int i = 0 ; i < MAX ; i++){
	    G[i].clear();
	    visited[i] = false;
	}
	int idx = 0;
	string s;
	map<string,int> mp;
	for(int i = 0 ; i < N ; i++){
	    cin >> s;
	    int p = s.find(":");
	    string s1,s2;
	    s1 = s.substr(0,p);
	    s2 = s.substr(p+1); s2.resize(s2.size()-1);
	    if(mp.find(s1) == mp.end()){
		mp[s1] = idx++;
	    }
	    stringstream ss(s2);
	    while(getline(ss,s2,',')){
		if(mp.find(s2) == mp.end()){
		    mp[s2] = idx++;
		}
		G[mp[s1]].push_back(mp[s2]);
	    }
	}
	st.clear();
	solve(0);
	cout << st.size() << endl;
    }
    return 0;
}
