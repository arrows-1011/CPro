#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 1000
 
struct State{
    string s;
    int next,l;
    State(string s,int next,int l) 
	: s(s),next(next),l(l) {}
};
 
int idx[MAX_N],len[MAX_N];
vector<State> G[MAX_N];
 
void solve(int x){
    if(len[x] == idx[x]){
	return;
    }
    for(int i = 0 ; i < len[x] ; i++){
	cout << string(G[x][idx[x]].l,'.') + G[x][idx[x]].s << endl;
	solve(G[x][idx[x]++].next);
    }
}
 
int main(){
    int N,K,size[MAX_N] = {0};
    string start,in;
    cin >> N >> size[0] >> start;
    for(int i = 1 ; i < N ; i++){
	cin >> K >> in;
	size[i] = size[K-1]+1;
	G[K-1].push_back(State(in,i,size[i]));
    }
    cout << start << endl;
    for(int i = 0 ; i < N ; i++){
	len[i] = G[i].size();
    }
    solve(0);
    return 0;
}
