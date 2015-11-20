#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 10
#define INF 1e9
typedef pair<int,string> P;
 
int N,bit;
string s[MAX_N];
string dp[1<<MAX_N][MAX_N];
vector<P> G[MAX_N];
 
void init(){
    bit = 0;
    for(int i = 0 ; i < (1<<N) ; i++){
	for(int j = 0 ; j < N ; j++){
	    dp[i][j] = "#";
	}
    }
}
 
string cat(const string &a,const string &b){
    int l1 = a.size(),l2 = b.size();
    for(int i = min(l1,l2) ; i >= 0 ; i--){
	string suba = a.substr(l1-i,i);
	string subb = b.substr(0,i);
	if(suba == subb){
	    return a + b.substr(i);
	}
    }
}
 
void overlap(int a,int b){
    string s1 = s[a], s2 = s[b];
    if(s2.find(s1) != string::npos &&
       s1.find(s2) == string::npos){
	bit |= (1<<a);
    }
    if(s1.find(s2) != string::npos &&
       s2.find(s1) == string::npos){
	bit |= (1<<b);
    }
}
 
string solve(int S,int v){
    if(S == (1<<N)-1){
	return s[v];
    }
    if(dp[S][v] != "#"){
	return dp[S][v];
    }
    string res = "#";
    for(int i = 0 ; i < N ; i++){
	if((S >> i) & 1) continue;
	string next = cat(s[v],solve(S|(1<<i),i));
	if(res == "#"){
	    res = next;
	}else{
	    if(next.size() < res.size()){
		res = next;
	    }else if(next.size() == res.size() && next < res){
		res = next;
	    }
	}
    }
    return dp[S][v] = res;
}
 
int main(){
    while(cin >> N, N > 0){
	init();
	for(int i = 0 ; i < N ; i++){
	    cin >> s[i];
	}
	if(N == 1){
	    cout << s[0] << endl;
	    continue;
	}
	for(int i = 0 ; i < N ; i++){
	    for(int j = 0 ; j < N ; j++){
		if(i == j) continue;
		overlap(i,j);
	    }
	}
	string res = "#";
	for(int i = 0 ; i < N ; i++){
	    if((bit >> i) & 1) continue;
	    string r = solve(bit|(1<<i),i);
	    if(res == "#"){
		res = r;
	    }else{
		if(r.size() < res.size()){
		    res = r;
		}else if(r.size() == res.size() && r < res){
		    res = r;
		}
	    }
	}
	cout << res << endl;
    }
    return 0;
}
