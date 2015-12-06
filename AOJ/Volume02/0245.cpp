#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define MAX_H 20
#define MAX_W 20
#define MAX_T 150

struct Data{
    int n,c,s,t;
    Data(){}
    Data(int n,int c,int s,int t) :
        n(n),c(c),s(s),t(t) {}

    bool operator < (const Data &d)const{
        return n < d.n;
    }
};

int H,W,LIMIT;
int memo[MAX_H][MAX_W][MAX_T][1<<8];
vector<Data> v;
char field[MAX_H][MAX_W];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}

bool check(int nt,int idx){
    return (v[idx].s <= nt && nt < v[idx].t);
}

int solve(int x,int y,int t,int p){
    if(t == LIMIT) return 0;
    int &res = memo[x][y][t][p];
    if(res != -1) return res;
    int S = p,cost = 0;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!inField(nx,ny)) continue;
        if(field[ny][nx] == '.') continue;
        int x = field[ny][nx]-'0';
        if(S >> x & 1) continue;
        if(check(t,x)){
            S |= (1<<x);
            cost += v[x].c;
        }
    }
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!inField(nx,ny)) continue;
        if(field[ny][nx] != '.') continue;
        res = max(res,solve(nx,ny,t+1,S)+cost);
    }
    return res;
}

int main(){
    int sx,sy,N;
    while(cin >> W >> H, W){
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                cin >> field[i][j];
                if(field[i][j] == 'P'){
                    sx = j; sy = i;
                    field[i][j] = '.';
                }
            }
        }
        LIMIT = 0;
        cin >> N;
        v.clear(); v.resize(N);
        for(int i = 0 ; i < N ; i++){
            cin >> v[i].n >> v[i].c >> v[i].s >> v[i].t;
            LIMIT = max(LIMIT,v[i].t);
        }
        LIMIT++;
        memset(memo,-1,sizeof(memo));
        cout << solve(sx,sy,0,0) << endl;
    }
    return 0;
}
