#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 110
#define MAX_R 110
#define MAX_D 110
 
struct State{
    int r,d;
    State(){}
    State(int r,int d) : r(r),d(d) {}
};
 
int D,N;
int a[MAX_N],e[MAX_N],r[MAX_N];
 
int bfs(){
    queue<State> Q; Q.push(State(0,D));
    queue<int> step; step.push(0);
    bool visited[MAX_R][MAX_D] = {{false}};
    visited[0][D] = true;
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int stp = step.front(); step.pop();
	if(s.d == 0){ return stp; }
	for(int i = 0 ; i < N ; i++){
	    State ns = (State){min(100,s.r+e[i]),max(0,s.d-a[i])};
	    if(s.r >= r[i] && !visited[ns.r][ns.d]){
		visited[ns.r][ns.d] = true;
		Q.push(ns);
		step.push(stp+1);
	    }
	}
    }
    return -1;
}
 
int main(){
    while(cin >> D >> N, D){
	for(int i = 0 ; i < N ; i++){
	    cin >> a[i] >> e[i] >> r[i];
	}
	int res = bfs();
	if(res == -1){
	    cout << "NA" << endl;
	}else{
	    cout << res << endl;
	}
    }
    return 0;
}
