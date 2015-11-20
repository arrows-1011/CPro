#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 110
#define INF (1<<29)
typedef pair<int,int> P;
typedef pair<int,P> PP;
 
int H,W;
int dist[MAX][MAX]; 
char field[MAX][MAX];
vector<P> M,Hole;
 
struct State{
    int x,y,cost,m;
    State(){}
    State(int x,int y,int cost,int m) : x(x), y(y), cost(cost), m(m) {}
};
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
void init(){
    fill(dist[0],dist[MAX],1);
    const int dx[] = {-1,-1,-1,0,0,1,1,1};
    const int dy[] = {-1,0,1,-1,1,-1,0,1};
    for(int i = 0 ; i < (int)Hole.size() ; i++){
	int x = Hole[i].first, y = Hole[i].second;
	for(int j = 0 ; j < 8 ; j++){
	    int nx = x + dx[j];
	    int ny = y + dy[j];
	    if(!inField(ny,nx)) continue;
	    dist[ny][nx] = max(dist[ny][nx],3);
	    for(int k = 0 ; k < 8 ; k++){
		int nnx = nx + dx[k];
		int nny = ny + dy[k];
		if(!inField(nny,nnx)) continue;
		dist[nny][nnx] = max(dist[nny][nnx],2);
	    }
	}
    }
}
 
int bfs(int sx,int sy,int gx,int gy){
    const int dx[] = {-1,0,0,1};
    const int dy[] = {0,-1,1,0};
    int d[MAX][MAX];
    fill(d[0],d[MAX],INF);
    d[sy][sx] = 0;
    priority_queue<PP,vector<PP>,greater<PP> > Q;
    Q.push(PP(0,P(sx,sy)));
 
    while(!Q.empty()){
	PP p = Q.top(); Q.pop();
	int x = p.second.first, y = p.second.second;
	if(x == gx && y == gy) break;
	for(int i = 0 ; i < 4 ; i++){
	    int nx = x + dx[i];
	    int ny = y + dy[i];
	    if(!inField(ny,nx)) continue;
	    if(field[ny][nx] == '#') continue;
	    if(d[ny][nx] <= d[y][x] + dist[y][x]) continue;
	    Q.push(PP(p.first+dist[y][x],P(nx,ny)));
	    d[ny][nx] = p.first + dist[y][x];
	}
    }
 
    return d[gy][gx];
}
 
void solve(int sx,int sy,int gx,int gy){
    int len = M.size(),ans = INF;
    int d[MAX][MAX][1<<5];
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    for(int k = 0 ; k < 1<<5 ; k++){
		d[i][j][k] = INF;
	    }
	}
    }
    d[sy][sx][0] = 0;
    queue<State> Q;
    Q.push(State(sx,sy,0,0));   
    init();
 
    while(!Q.empty()){
	State S = Q.front(); Q.pop();
	bool ok = true;
	for(int i = 0 ; i < len ; i++){
	    if(!(S.m >> i & 1)){
		ok = false; 
		break;
	    } 
	}
	if(ok && S.x == gx && S.y == gy){
	    ans = min(ans,S.cost);
	    continue;
	}
	if(ok){
	    S.cost += bfs(S.x,S.y,gx,gy);
	    ans = min(ans,S.cost);   
	}else{
	    for(int i = 0 ; i < len ; i++){
		if(S.m >> i & 1) continue;
		State next;
		next.cost = S.cost + bfs(S.x,S.y,M[i].first,M[i].second);
		next.m = S.m | 1<<i; next.x = M[i].first; next.y = M[i].second;
		if(next.cost < d[next.y][next.x][next.m]){
		    d[next.y][next.x][next.m] = next.cost;
		    Q.push(next);
		}
	    }
	}
    }
    cout << ans << endl;
}
 
int main(){
    int sx,sy,gx,gy;
    cin >> W >> H;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> field[i][j];
	    if(field[i][j] == 'S'){
		sx = j; sy = i;
	    }else if(field[i][j] == 'G'){
		gx = j; gy = i;
	    }else if(field[i][j] == 'M'){
		M.push_back(P(j,i));
	    }else if(field[i][j] == '#'){
		Hole.push_back(P(j,i));
	    }
	}
    }
    solve(sx,sy,gx,gy);
 
    return 0;
}
