#include <bits/stdc++.h>

using namespace std;

#define MAX_H 15
#define MAX_W 15
#define MAX_O 55
#define INF (1<<29)

struct State{
    int cost,x,y,o;
    State(){}
    State(int cost,int x,int y,int o) :
        cost(cost),x(x),y(y),o(o) {}

    bool operator < (const State &s)const{
        if(cost != s.cost){
            return cost > s.cost;
        }else{
            return o < s.o;
        }
    }
};

int main(){
    int W,H,f,m,o;
    while(cin >> W >> H, W){
        cin >> f >> m >> o;
        vector<vector<int> > G(H+1,vector<int>(W,0));
        for(int i = 1 ; i <= H ; i++){
            for(int j = 0 ; j < W ; j++){
                cin >> G[i][j];
            }
        }

        const int dx[] = {-1,0,1}, dy[] = {0,1,0};
        bool reachable = 0;
        
        priority_queue<State> Q;
        Q.push(State(0,0,0,o));
        
        int d[MAX_H][MAX_W][MAX_O];
        for(int i = 0 ; i < MAX_H ; i++){
            for(int j = 0 ; j < MAX_W ; j++){
                for(int k = 0 ; k < MAX_O ; k++){
                    d[i][j][k] = INF;
                }
            }
        }
        d[0][0][o] = 0;
        
        while(!Q.empty()){
            State s = Q.top(); Q.pop();
            int x = s.x,y = s.y; o = s.o;
            if(o == 0) continue;
            if(y == H){
                if(s.cost <= f){
                    reachable = 1;
                    cout << s.cost << endl;
                }
                break;
            }
            if(o == 1) continue;
            for(int i = 0 ; i < 3 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= W) continue;
                if(G[ny][nx] < 0){
                    if(d[y][x][o] - G[ny][nx] < d[ny][nx][o-1]){
                        d[ny][nx][o-1] = d[y][x][o] - G[ny][nx];
                        Q.push(State(d[ny][nx][o-1],nx,ny,o-1));
                    }
                }else if(G[ny][nx] > 0){
                    int no = min(o+G[ny][nx]-1,m);
                    if(d[y][x][o] < d[ny][nx][no]){
                        d[ny][nx][no] = d[y][x][o];
                        Q.push(State(d[ny][nx][no],nx,ny,no));
                    }
                }else{
                    if(d[y][x][o] < d[ny][nx][o]){
                        d[ny][nx][o] = d[y][x][o];
                        Q.push(State(d[ny][nx][o],nx,ny,o));
                    }
                }
            }
        }
        if(!reachable){
            cout << "NA" << endl;
        }
    }
    return 0;
}
