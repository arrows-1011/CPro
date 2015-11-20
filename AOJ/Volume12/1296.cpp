#include <bits/stdc++.h>
  
using namespace std;
  
struct State{
    string s;
    int d;
};
  
int N,size[10];
string a[10],b[10],src,dst,str;
  
int solve(){
    queue<State> Q;
    Q.push((State){src,0});
    set<string> visited;
    visited.insert(src);
  
    while(!Q.empty()){
	State now = Q.front(); Q.pop();
	string s = now.s;
	if(s == dst) return now.d;
      
	for(int i = 0 ; i < N ; i++){
	    string next;
	    for(int j = 0 ; j < (int)s.size() ; j++){
		string sub = s.substr(j,size[i]);
		if(sub == a[i]){
		    next += b[i];
		    j += size[i]-1;
		}else{
		    next += s[j];
		}
	    }
	    if(next.size() > dst.size()) continue;
	    if(!visited.count(next)){
		visited.insert(next);
		Q.push((State){next,now.d+1});
	    }
	}
    }
    return -1;
}
  
int main(){
    while(cin >> N, N){
	for(int i = 0 ; i < N ; i++){
	    cin >> a[i] >> b[i];
	    size[i] = a[i].size();
	}
	cin >> src >> dst;
	cout << solve() << endl;
    }
    return 0;
}
