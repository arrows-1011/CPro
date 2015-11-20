#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_N 366
#define MAX_C 9
#define MAX_R 2402
 
struct State{
    int d,c,r[4];
    State(int d,int c,int r[4]) : d(d),c(c) {
	for(int i = 0 ; i < 4 ; i++){
	    this->r[i] = r[i];
	}
    }
};
 
int N,arr[MAX_N];
bool visited[MAX_N][MAX_C][MAX_R];
const int d[5] = {-1,-3,1,3,0};
 
int next(int c,int dir){
    if(c%3 == 0 && dir == 0) return -1;
    if(c/3 == 0 && dir == 1) return -1;
    if(c%3 == 2 && dir == 2) return -1;
    if(c/3 == 2 && dir == 3) return -1;
    return c + d[dir];
}
 
bool check(int d,int c){
    c += c/3;
    for(int i = 0 ; i < 16 ; i++){
	if((arr[d] >> i & 1) && i == c) return true;
	if((arr[d] >> i & 1) && i == c+1) return true;
	if((arr[d] >> i & 1) && i == c+4) return true;
	if((arr[d] >> i & 1) && i == c+5) return true;
    }
    return false;
}
 
void calc(int c,int *r){
    if(c == 0){ r[0] = 0; }else{ r[0]++; }
    if(c == 2){ r[1] = 0; }else{ r[1]++; }
    if(c == 6){ r[2] = 0; }else{ r[2]++; }
    if(c == 8){ r[3] = 0; }else{ r[3]++; }
}
 
int getValue(int *r){
    int res = 0;
    for(int i = 0 ; i < 4 ; i++){
	res *= 7; res += r[i];
    }
    return res;
}
 
int solve(){
    int r[4] = {0}; calc(4,r);
    memset(visited,false,sizeof(visited));
    visited[0][4][getValue(r)] = true;
    queue<State> Q;
    Q.push(State(0,4,r));
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int day = s.d,cloud = s.c;
	if(check(day,cloud)) continue;
	if(day == N-1) return 1;
	for(int i = 0 ; i < 5 ; i++){
	    int cc = cloud,nr[4];
	    for(int j = 0 ; j < 2 ; j++){
		int nc = next(cc,i);
		if(nc == -1) break;
		memcpy(nr,s.r,sizeof(nr)); calc(nc,nr);
		if(*max_element(nr,nr+4) >= 7){
		    cc = nc;
		    continue;
		}
		int value = getValue(nr);
		if(!visited[day+1][nc][value]){
		    visited[day+1][nc][value] = true;
		    Q.push(State(day+1,nc,nr));
		}
		cc = nc;
		if(i == 4) break;
	    }
	}
    }
    return 0;
}
 
int main(){
    while(cin >> N,N){
	for(int i = 0 ; i < N ; i++){
	    int x,bit = 0;
	    for(int j = 0 ; j < 16 ; j++){
		cin >> x;
		if(x == 1){ bit |= (1<<j); }
	    }
	    arr[i] = bit;
	}
	cout << solve() << endl;
    }
    return 0;
}
