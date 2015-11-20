#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 15
#define MAX_W 15
 
int p,c;
 
class State{
public:
    int x,y,px[3],py[3],cx[3],cy[3];
    bool operator < (const State &s)const{
	if(x != s.x){
	    return x < s.x;
	}else if(y != s.y){
	    return y < s.y;
	}else{
	    for(int i = 0 ; i < p ; i++){
		if(px[i] != s.px[i]){
		    return px[i] < s.px[i];
		}else if(py[i] != s.py[i]){
		    return py[i] < s.py[i];
		}
	    }
	    for(int i = 0 ; i < c ; i++){
		if(cx[i] != s.cx[i]){
		    return cx[i] < s.cx[i];
		}else if(cy[i] != s.cy[i]){
		    return cy[i] < s.cy[i];
		}
	    }
	    return false;
	}
    }
};
 
int H,W,gx,gy;
set<State> visited;
char field[MAX_H][MAX_W];
State start;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
 
void init(){
    p = c = 0;
    visited.clear();
}
 
bool input(){
    cin >> H >> W;
    if(H == 0 && W == 0){
	return false;
    }
    init();
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	    if(field[i][j] == '@'){
		start.x = j; start.y = i;
	    }else if(field[i][j] == 'E'){
		gx = j; gy = i;
	    }else if(field[i][j] == 'w'){
		start.px[p] = j; start.py[p] = i;
		p++;
	    }else if(field[i][j] == 'c'){
		field[i][j] = '.';
		start.cx[c] = j; start.cy[c] = i;
		c++;
	    }
	}
    }
    return true;
}
 
inline bool valid(const State &s){
    if(field[s.y][s.x] == '#'){
	return false;
    }
    for(int i = 0 ; i < p ; i++){
	if(s.x == s.px[i] && s.y == s.py[i]){
	    return false;
	}
    }
    for(int i = 0 ; i < c ; i++){
	if(s.x == s.cx[i] && s.y == s.cy[i]){
	    return false;
	}
    }
    return true;
}
 
inline bool pushCont(State &s,int dir){
    int idx = -1;
    int nx = s.x + dx[dir], ny = s.y + dy[dir];
    for(int i = 0 ; i < c ; i++){
	if(s.cx[i] == nx && s.cy[i] == ny){
	    idx = i;
	    break;
	}
    }
    if(idx == -1){ return false; }
    while(true){
	nx += dx[dir], ny += dy[dir];
	if(field[ny][nx] == '#'){
	    s.cx[idx] = nx-dx[dir];
	    s.cy[idx] = ny-dy[dir];
	    return true;
	}
	for(int i = 0 ; i < c ; i++){
	    if(i == idx) continue;
	    if(s.cx[i] == nx && s.cy[i] == ny){
		s.cx[idx] = nx-dx[dir];
		s.cy[idx] = ny-dy[dir];
		return true;
	    }
	}
	for(int i = 0 ; i < p ; i++){
	    if(s.px[i] == nx && s.py[i] == ny){
		s.px[i] = s.py[i] = -1;
		s.cx[idx] = s.cy[idx] = -1;
		return true;
	    }
	}
    }
    return false;
}
 
int solve(){
    deque<State> Q;
    deque<int> move;
    Q.push_front(start);
    move.push_front(0);
    visited.insert(start);
 
    while(!Q.empty()){
	State s = Q.front(); Q.pop_front();
	int m = move.front(); move.pop_front();
	if(s.x == gx && s.y == gy){
	    return m;
	}
	for(int i = 0 ; i < 4 ; i++){
	    State tmp = s;
	    s.x += dx[i], s.y += dy[i];
	    if(valid(s)){
		if(!visited.count(s)){
		    visited.insert(s);
		    Q.push_back(s);
		    move.push_back(m+1);
		}
	    }
	    s.x -= dx[i], s.y -= dy[i];
	    if(pushCont(s,i)){
		if(!visited.count(s)){
		    visited.insert(s);
		    Q.push_front(s);
		    move.push_front(m);
		}
	    }
	    s = tmp;
	}
    }
    return -1;
}
 
int main(){
    while(input()){
	cout << solve() << endl;
    }
    return 0;
}
