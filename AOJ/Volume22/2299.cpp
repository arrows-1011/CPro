#include <bits/stdc++.h>

using namespace std;

#define MAX_H 500
#define MAX_W 500
#define F first
#define S second
typedef pair<int,int> pii;

int H,W;
char field[MAX_H][MAX_W];
vector<pii> v[26];

bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}

int calc(int x,int y){
    for(int i = 0 ; i < 26 ; i++){
        v[i].clear();
    }
    const int dx[] = {-1,0,1,0};
    const int dy[] = {0,-1,0,1};
    for(int i = 0 ; i < 4 ; i++){
        int nx = x, ny = y;
        while(1){
            nx += dx[i]; ny += dy[i];
            if(!inField(nx,ny)) break;
            if(field[ny][nx] != '.'){
                v[field[ny][nx]-'A'].push_back(pii(nx,ny));
                break;
            }
        }
    }
    int res = 0;
    for(int i = 0 ; i < 26 ; i++){
        if(v[i].size() == 2){
            field[v[i][0].S][v[i][0].F] = '.';
            field[v[i][1].S][v[i][1].F] = '.';
            res += 2;
        }
    }
    return res;
}

int main(){
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
        for(int j = 0 ; j < W ; j++){
            cin >> field[i][j];
        }
    }
    int res = 0;
    bool update = 1;
    while(update){
        update = 0;
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                if(field[i][j] != '.') continue;
                int r = calc(j,i);
                if(r > 0){
                    res += r;
                    update = 1;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
