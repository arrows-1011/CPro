#include <bits/stdc++.h>
  
using namespace std;
  
int N;
  
int solve(string &s,string &t){
    queue<string> Q;
    map<string,int> dist;
    Q.push(s);
    dist[s] = 0;
    while(!Q.empty()){
	string v = Q.front(); Q.pop();
	if(v == t) return dist[v];
	int i;
	for(i = 0 ; i < N ; i++){
	    if(v[i] != t[i]) break;
	}
	string next = v;
	int diff = (t[i]-v[i]+10)%10;
	for(int j = i ; j < N ; j++){
	    next[j] = ((next[j]-'0' + diff) % 10) + '0';
	    if(dist.find(next) == dist.end()){
		dist[next] = dist[v] + 1;
		Q.push(next);
	    }
	}
    }
}
  
int main(){
    string s,t;
    while(cin >> N, N){
	cin >> s >> t;
	cout << solve(s,t) << endl;
    }
    return 0;
}
