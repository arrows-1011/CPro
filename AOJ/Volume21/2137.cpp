#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 16
 
int H,W,gp[MAX*MAX];
char field[MAX][MAX];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
 
struct State{
    int h,r[3];
};
 
inline bool check(const State &s){
    for(int i = 0 ; i < 3 ; i++){
	if(field[s.r[i]/W][s.r[i]%W] != '_'){
	    return false;
	}
    }
    return true;
}
 
inline int canMove(const State &s,int &dir){
    if(field[s.h/W][s.h%W] == '#') return -1;
    int idx = -1;
    for(int i = 0 ; i < 3 ; i++){
	if(s.h == s.r[i]){
	    idx = i; break;
	}
    }
    if(idx == -1) return 3;
    int nx = s.h%W + dx[dir];
    int ny = s.h/W + dy[dir];
    if(field[ny][nx] == '#') return -1;
    for(int i = 0 ; i < 3 ; i++){
	if(i == idx) continue;
	if(s.r[i]%W == nx && s.r[i]/W == ny){
	    return -1;
	}
    }
    return idx;
}
 
bool visited[50][50][50][50];
 
int bfs(const State &S){
    queue<State> Q; Q.push(S);
    queue<int> step; step.push(0);
    const int dr[4] = {-1,-W,1,W};
    memset(visited,false,sizeof(visited));
    visited[gp[S.h]][gp[S.r[0]]][gp[S.r[1]]][gp[S.r[2]]] = true;
 
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int st = step.front(); step.pop();
	if(check(s)) return st;
	for(int i = 0 ; i < 4 ; i++){
	    s.h += dr[i];
	    int r = canMove(s,i);
	    if(r == -1){
		s.h -= dr[i];
		continue;
	    }
	    if(r == 3){
		if(!visited[gp[s.h]][gp[s.r[0]]][gp[s.r[1]]][gp[s.r[2]]]){
		    visited[gp[s.h]][gp[s.r[0]]][gp[s.r[1]]][gp[s.r[2]]] = true;
		    Q.push(s);
		    step.push(st+1);
		}
	    }else{
		s.r[r] += dr[i];
		if(!visited[gp[s.h]][gp[s.r[0]]][gp[s.r[1]]][gp[s.r[2]]]){
		    visited[gp[s.h]][gp[s.r[0]]][gp[s.r[1]]][gp[s.r[2]]] = true;
		    Q.push(s);
		    step.push(st+1);
		}
		s.r[r] -= dr[i];
	    }
	    s.h -= dr[i];
	}
    }
    return -1;
}
 
int main(){
    while(cin >> W >> H,(W|H)){
	int r = 0,idx = 0;
	State start;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == '@'){
		    start.h = i*W+j;
		}else if(field[i][j] == '*'){
		    start.r[r++] = i*W+j;
		}
		if(field[i][j] != '#'){
		    gp[i*W+j] = idx++;
		}
	    }
	}
	cout << bfs(start) << endl;
    }
    return 0;
}
