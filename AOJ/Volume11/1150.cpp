#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 61
#define MAX_W 31
#define INF 1e9
#define Fi first
#define Se second
typedef pair<int,int> pii;
 
struct State{
    int d,lx,ly,rx,ry;
    bool f;
    State(){}
    State(int d,int lx,int ly,int rx,int ry,bool f) :
	d(d),lx(lx),ly(ly),rx(rx),ry(ry),f(f) {}
    bool operator > (const State &s)const{
	return d > s.d;
    }
};
 
int W,H;
int ps,pt;
pii S[MAX_W],T[MAX_W];
char field[MAX_H][MAX_W];
int dist[MAX_H][MAX_W][MAX_H][MAX_W][2];
 
const int dx[9] = {1,1,1,1,1,2,2,2,3};
const int dy[9] = {-2,-1,0,1,2,-1,0,1,0};
 
bool inField(int x,int y){
    return 0 <= x && x < W && 0 <= y && y < H;
}
 
int dijkstra(){
    priority_queue<State,vector<State>,greater<State> > Q;
    fill(dist[0][0][0][0],dist[0][0][0][0]+MAX_H*MAX_W*MAX_H*MAX_W*2,INF);
    for(int i = 0 ; i < ps ; i++){
	Q.push(State(0,S[i].Fi,S[i].Se,W,H,0)); 
	Q.push(State(0,W,H,S[i].Fi,S[i].Se,1));
	dist[S[i].Se][S[i].Fi][H][W][0] = 0;
	dist[H][W][S[i].Se][S[i].Fi][1] = 0;
    }
 
    while(!Q.empty()){
	State s = Q.top(); Q.pop();
	int lx = s.lx, ly = s.ly;
	int rx = s.rx, ry = s.ry;
 
	if(dist[ly][lx][ry][rx][s.f] < s.d) continue;
	for(int i = 0 ; i < pt ; i++){
	    if(lx == T[i].Fi && ly == T[i].Se ||
	       rx == T[i].Fi && ry == T[i].Se){
		return s.d;
	    }
	}
	if(s.f){
	    for(int i = 0 ; i < 9 ; i++){
		int nlx = rx - dx[i];
		int nly = ry + dy[i];
		if(!inField(nlx,nly)) continue;
		if(field[nly][nlx] == 'X') continue;
		int t = field[nly][nlx] - '0';
		if(s.d + t < dist[nly][nlx][ry][rx][0]){
		    dist[nly][nlx][ry][rx][0] = s.d + t;
		    Q.push(State(dist[nly][nlx][ry][rx][0],nlx,nly,rx,ry,0));
		}
	    }
	}else{
	    for(int i = 0 ; i < 9 ; i++){
		int nrx = lx + dx[i];
		int nry = ly + dy[i];
		if(!inField(nrx,nry)) continue;
		if(field[nry][nrx] == 'X') continue;
		int t = field[nry][nrx] - '0';
		if(s.d + t < dist[ly][lx][nry][nrx][1]){
		    dist[ly][lx][nry][nrx][1] = s.d + t;
		    Q.push(State(dist[ly][lx][nry][nrx][1],lx,ly,nrx,nry,1));
		}
	    }
	}
    }
    return -1;
}
 
int main(){
    dijkstra();
    while(cin >> W >> H, W){
	ps = pt = 0;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
		if(field[i][j] == 'S'){
		    S[ps++] = pii(j,i);
		    field[i][j] = '0';
		}else if(field[i][j] == 'T'){
		    T[pt++] = pii(j,i);
		    field[i][j] = '0';      
		}
	    }
	}
	cout << dijkstra() << endl;
    }
    return 0;
}
