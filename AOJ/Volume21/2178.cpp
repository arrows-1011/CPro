#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 20000
typedef pair<int,int> pii;
 
map<pii,int> id;
map<int,pii> mp;
int color[MAX][2],tmp[MAX][2];
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
 
struct State{
    int v,p,col;
    State(int v,int p,int col) :
	v(v),p(p),col(col) {}
};
 
bool bfs(int v,int p){
    queue<State> Q;
    Q.push(State(v,p,0));
    Q.push(State(v+1,1-p,1));
   
    while(!Q.empty()){
	State s = Q.front(); Q.pop();
	pii np = mp[s.v];
	if(color[s.v/2][s.p] >= 0){
	    if(color[s.v/2][s.p] != s.col){
		return false;
	    }
	    continue;
	}
	color[s.v/2][s.p] = s.col;
	for(int i = 0 ; i < 4 ; i++){
	    int nx = np.first+dx[i],ny = np.second+dy[i];
	    if(id.find(pii(nx,ny)) != id.end()){
		int x = id[pii(nx,ny)]%2;
		if(id[np]/2 == id[pii(nx,ny)]/2){
		    Q.push(State(id[pii(nx,ny)],1-s.p,1-s.col));
		}else{
		    Q.push(State(id[pii(nx,ny)],(x&1?1:0),s.col));
		}
	    }
	}
    }
    return true;
}
 
void init(){
    mp.clear();
    id.clear();
    memset(color,-1,sizeof(color));
}
 
int main(){
    int N,x,y;
    char ch;
    while(cin >> N,N){
	init();
	for(int i = 0 ; i < N ; i++){
	    cin >> x >> y >> ch;
	    int j = i*2;
	    if(ch == 'x'){
		mp[j] = pii(x,y); mp[j+1] = pii(x+1,y);
		id[pii(x,y)] = j; id[pii(x+1,y)] = j+1;
	    }else{
		mp[j] = pii(x,y); mp[j+1] = pii(x,y+1);
		id[pii(x,y)] = j; id[pii(x,y+1)] = j+1;
	    }
	}
	bool can = true;
	for(int i = 0 ; i < 2*N ; i+=2){
	    if(color[i/2][0] >= 0) continue;
	    for(int j = 0 ; j < N ; j++){
		for(int k = 0 ; k < 2 ; k++){
		    tmp[j][k] = color[j][k];
		}
	    }
	    if(!bfs(i,0)) can = false;
	    if(!can){
		can = true;
		for(int j = 0 ; j < N ; j++){
		    for(int k = 0 ; k < 2 ; k++){
			color[j][k] = tmp[j][k];
		    }
		}
		if(!bfs(i,1)){
		    can = false;
		    break;
		}
	    }
	}
	cout << (can ? "Yes" : "No") << endl;
    }
    return 0;
}
