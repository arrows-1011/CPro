#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 30
#define INF 1e9
 
class Dice{
private:
    int tmp;
public:
    vector<int> d;
   
    void init(){
	d.resize(6);
    }
 
    int getTop(){
	return d[0];
    }
 
    int getFront(){
	return d[1];
    }
 
    int getRight(){
	return d[2];
    }
 
    void rollN(){
	tmp = d[0];
	d[0] = d[1];
	d[1] = d[5];
	d[5] = d[4];
	d[4] = tmp;
    }
   
    void rollE(){
	tmp = d[0];
	d[0] = d[3];
	d[3] = d[5];
	d[5] = d[2];
	d[2] = tmp;
    }
  
    void rollS(){
	tmp = d[0];
	d[0] = d[4];
	d[4] = d[5];
	d[5] = d[1];
	d[1] = tmp;
    }
  
    void rollW(){
	tmp = d[0];
	d[0] = d[2];
	d[2] = d[5];
	d[5] = d[3];
	d[3] = tmp;
    }
};
 
int H,W,sx,sy;
int field[MAX][MAX];
bool visited[MAX][MAX][6][6][6][6];
 
struct State{
    int x,y,n,dist;
    Dice d;
   
    State(int x,int y,int n,int dist,Dice d) : 
	x(x),y(y),n(n),dist(dist),d(d) {}
};
 
int ctoi(char ch){
    switch(ch){
    case 'k':
	return -1;
    case 'r':
	return 0;
    case 'g':
	return 1;
    case 'b':
	return 2;
    case 'c':
	return 3;
    case 'm':
	return 4;
    case 'y':
	return 5;
    case 'w':
	return 6;
    }
    return -1;
}
 
bool inField(int x,int y){
    return 0 <= x && x < W && 0 <= y && y < H;
}
 
Dice init(){
    Dice d; d.init();
    d.d[0] = 0;
    d.d[1] = 4;
    d.d[2] = 2;
    d.d[3] = 5;
    d.d[4] = 1;
    d.d[5] = 3;
    return d;
}
 
void solve(Dice &dice){
    Dice initDice = init(); 
    int ans = INF;
    const int dx[4] = {-1,0,1,0};
    const int dy[4] = {0,-1,0,1};
    queue<State> Q;
    Q.push(State(sx,sy,0,0,initDice));
    memset(visited,false,sizeof(visited));
  
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	int x = s.x,y = s.y,n = s.n;
	Dice d = s.d;
	int t = d.getTop(),f = d.getFront(),r = d.getRight();
 
	if(visited[y][x][t][f][r][n]) continue;
	visited[y][x][t][f][r][n] = true;
	if(n == 6){ ans = s.dist; break; }
 
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i], ny = y + dy[i];
	    if(!inField(nx,ny)) continue;
	    if(field[ny][nx] == -1) continue;
	    Dice nd = d;
	    if(i == 0){
		nd.rollW();
	    }else if(i == 1){
		nd.rollN();
	    }else if(i == 2){
		nd.rollE();
	    }else{
		nd.rollS();
	    }
	    if(field[ny][nx] == nd.getTop() && field[ny][nx] == dice.d[n]){
		Q.push(State(nx,ny,n+1,s.dist+1,nd));
	    }else if(field[ny][nx] == 6){
		Q.push(State(nx,ny,n,s.dist+1,nd));
	    }
	}
    }
    if(ans == INF){
	cout << "unreachable" << endl;
    }else{
	cout << ans << endl;
    }
}
 
int main(){
    char in;
    while(cin >> W >> H, W){
	Dice dice; dice.init();
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> in;
		if(in == '#'){
		    in = 'w';
		    sx = j; sy = i;
		}
		field[i][j] = ctoi(in);
	    }
	}
	for(int i = 0 ; i < 6 ; i++){
	    cin >> in;
	    dice.d[i] = ctoi(in);
	}
	solve(dice);
    }
    return 0;
}
