#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 55
#define MAX_W 55
typedef pair<int,int> pii;
 
struct State{
    int d,x,y,dir,hand;
    State(){}
    State(int d,int x,int y,int dir,int hand) :
        d(d),x(x),y(y),dir(dir),hand(hand) {}
    bool operator < (const State &s)const{
        return d > s.d;
    }
    bool operator == (const State &s)const{
        if(x != s.x) return 0;
        if(y != s.y) return 0;
        if(dir != s.dir) return 0;
        if(hand != s.hand) return 0;
        return 1;
    }
};
 
int H,W,_dir,sx,sy,gx,gy;
char field[MAX_H][MAX_W];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int dx2[4][4] = {{-1,-1,0,-1},{0,1,1,1},{1,1,0,-1},{0,-1,-1,-1}};
const int dy2[4][4] = {{0,-1,-1,-1},{-1,-1,0,1},{0,1,1,1},{1,1,0,-1}};
 
int getDir(char ch){
    if(ch == '<') return 0;
    if(ch == '^') return 1;
    if(ch == '>') return 2;
    if(ch == 'v') return 3;
    return -1;
}
 
bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}
 
int solve(){
    int d[MAX_H][MAX_W][4][4];
    State prev[MAX_H][MAX_W][4][4],gs;
    memset(d,1,sizeof(d));
    d[sy][sx][_dir][2] = 0;
    memset(prev,-1,sizeof(prev));
    priority_queue<State> Q;
    Q.push(State(0,sx,sy,_dir,2));
     
    State ss = State(0,sx,sy,_dir,2);
    bool can = false;
     
    while(!Q.empty()){
        State s = Q.top(); Q.pop();
        int x = s.x,y = s.y,dir = s.dir,h = s.hand;
        if(x == gx && y == gy){
            can = true; gs = s;
            break;
        }
        int ncost = d[y][x][dir][h] + 1;
        int nx = x + dx[dir], ny = y + dy[dir];
        if(inField(nx,ny) && field[ny][nx] != '#' && (h == 1 || h == 2)){
            int nh = (h == 1 ? 2 : 3);
            if(ncost < d[ny][nx][dir][nh]){
                d[ny][nx][dir][nh] = ncost;
                prev[ny][nx][dir][nh] = s;
                Q.push(State(ncost,nx,ny,dir,nh));
            }
        }
 
        int ndir = (dir+1) % 4;
        if(h >= 2){
            int nh = (h == 2 ? 0 : 1);
            if(ncost < d[y][x][ndir][nh]){
                d[y][x][ndir][nh] = ncost;
                prev[y][x][ndir][nh] = s;
                Q.push(State(ncost,x,y,ndir,nh));       
            }
        }
         
        ndir = (dir-1+4) % 4;
        if(h <= 1){
            int nh = (h == 0 ? 2 : 3);
            if(ncost < d[y][x][ndir][nh]){
                d[y][x][ndir][nh] = ncost;
                prev[y][x][ndir][nh] = s;
                Q.push(State(ncost,x,y,ndir,nh));       
            }
        }
 
        for(int i = 0 ; i < 4 ; i++){
            if(abs(h-i) != 1 && !((i == 0 && h == 2) || (i == 2 && h == 0))) continue;
            int nx = x + dx2[dir][i];
            int ny = y + dy2[dir][i];
            if(!inField(nx,ny) || field[ny][nx] == '#'){
                if(ncost < d[y][x][dir][i]){
                    d[y][x][dir][i] = ncost;
                    prev[y][x][dir][i] = s;
                    Q.push(State(ncost,x,y,dir,i));     
                }
            }
        }
    }
     
    if(!can) return -1;
    set<pii> st;
    for(;;){
        int x = gs.x,y = gs.y,dir = gs.dir,h = gs.hand;
        st.insert(pii(x,y));
        if(gs == ss) break;
        gs = prev[y][x][dir][h];
    }
    return (st.size());
}
 
int main(){
    bool found = 0;
    cin >> H >> W;
    _dir = -1;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> field[i][j];
            _dir = max(_dir,getDir(field[i][j]));
            if(_dir >= 0 && !found){
                found = 1;
                sx = j; sy = i;
            }
            if(field[i][j] == 'G'){
                field[i][j] = '.';
                gx = j; gy = i;
            }
        }
    }
    cout << solve() << endl;
    return 0;
}
