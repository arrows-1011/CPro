#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1010
 
struct P{
    int p,l;
};
 
P p[MAX_N];
string s[MAX_N];
bool used[MAX_N];
int N;
 
void init(int N){
    for(int i = 0 ; i < N ; i++){
	p[i].p = i;
    }
}
 
bool find(int x,int target){
    if(p[x].p == target){
	return true;
    }
    if(p[x].p == x) return false;
    return find(p[x].p,target);
}
 
void make(int n,int parent,int root,int depth){
    set<int> children;
    if(used[n]){ return; }
    used[n] = true;
    p[n].p = parent; p[n].l = depth;
    for(int i = n+1 ; i < N ; i++){
	int len = s[i].size();
	if(depth+1 >= len) continue;
	if(s[i][depth] != '.') break;
	if(s[i][depth] == '.' && s[i][depth+1] != '.'){
	    children.insert(i);
	    make(i,n,root,depth+1);
	}
    }
}
 
int main(){
    int M;
    while(cin >> N >> M, N){
	map<string,int> mp;
	int cur = 0;
	init(N); cin.ignore();
	for(int i = 0 ; i < N ; i++){
	    getline(cin,s[i]);
	    for(int j = 0 ; j < (int)s[i].size() ; j++){
		if(s[i][j] != ' '){
		    mp[s[i].substr(j)] = cur++;
		    break;
		}
		s[i][j] = '.';
	    }
	    used[i] = false;
	}
	for(int i = 0 ; i < N ; i++){
	    if(used[i]) continue;
	    if(s[i][0] != '.'){
		make(i,i,i,0);
	    }
	}
	string ord,a,b,c;
	for(int i = 0 ; i < M ; i++){
	    getline(cin,ord);
	    stringstream ss(ord);
	    ss >> a;
	    ss >> ord; ss >> ord;
	    ss >> c;
	    ss >> ord;
	    ss >> b;
	    b.resize(b.size()-1);
	    bool ans = false;
	    if(c == "parent"){
		if(p[mp[b]].p == mp[a]){
		    ans = true;
		}
	    }else if(c == "child"){
		if(p[mp[a]].p == mp[b]){
		    ans = true;
		}
	    }else if(c == "ancestor"){
		if(p[mp[a]].l < p[mp[b]].l && find(mp[b],mp[a])){
		    ans = true;
		}
	    }else if(c == "descendant"){
		if(p[mp[a]].l > p[mp[b]].l && find(mp[a],mp[b])){
		    ans = true;
		}
	    }else{
		if(p[mp[a]].l == p[mp[b]].l && p[mp[a]].p == p[mp[b]].p){
		    ans = true;
		}
	    }
	    cout << (ans ? "True" : "False") << endl;
	}
	cout << endl;
    }
    return 0;
}
