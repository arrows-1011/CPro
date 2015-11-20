#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 35
typedef vector<char> Vec;
typedef vector<Vec> Mat;
 
struct Person{
    int x,y,d;
    Person(){}
    Person(int x,int y,int d)
        : x(x),y(y),d(d) {}
};
 
int W,H;
vector<Person> v;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
 
bool inField(int x,int y){
    return (0 <= x && x < W && 0 <= y && y < H);
}
 
int getD(int d,int x){
    int v[] = {1,0,3,2};
    return (v[(x-d+4)%4]);
}
 
void solve(Mat &maze){
    for(int T = 0 ; T < 180 ; T++){
        int N = v.size();
        vector<Person> v2(N),v3 = v;
        int cnt[MAX][MAX] = {{}},num[MAX][MAX];
        memset(num,-1,sizeof(num));
 
        for(int i = 0 ; i < N ; i++){
            int d = (4 - v[i].d) % 4;
            for(int j = 0 ; j < 4 ; j++){
                int nd = (d + j) % 4;
                int nx = v[i].x + dx[nd];
                int ny = v[i].y + dy[nd];
                if(maze[ny][nx] == '.' || maze[ny][nx] == 'X'){
                    cnt[ny][nx]++;
                    num[v[i].y][v[i].x] = i;
                    v2[i] = Person(nx,ny,getD(v[i].d,j));
                    v3[i].d = getD(v[i].d,j);
                    break;
                }
            }
        }
        v.clear();
        bool used[MAX*MAX] = {0};
        const int dx2[] = {1,0,-1,0};
        const int dy2[] = {0,-1,0,1};
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                if(cnt[i][j] == 0) continue;
                for(int k = 0 ; k < 4 ; k++){
                    int nx = j + dx2[k];
                    int ny = i + dy2[k];
                    int idx = num[ny][nx];
                    if(!inField(nx,ny)) continue;
                    if(i != v2[idx].y ||
                       j != v2[idx].x) continue;
                     
                    if(idx != -1){
                        maze[ny][nx] = '.';
                        if(maze[i][j] == '.'){
                            maze[i][j] = '*';
                            v.push_back(v2[idx]);
                        }
                        used[idx] = 1;
                        break;
                    }
                }
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(!used[i]){
                v.push_back(v3[i]);
            }
        }
        if(v.size() == 0){
            cout << T+1 << endl;
            return;
        }
    }
    cout << "NA" << endl;
}
 
int main(){
    while(cin >> W >> H, W){
        Mat maze(H,Vec(W));
        v.clear();
        for(int i = 0 ; i < H ; i++){
            for(int j = 0 ; j < W ; j++){
                cin >> maze[i][j];
                if(maze[i][j] == 'N'){
                    maze[i][j] = '*';
                    v.push_back(Person(j,i,0));
                }else if(maze[i][j] == 'E'){
                    maze[i][j] = '*';
                    v.push_back(Person(j,i,1));
                }else if(maze[i][j] == 'S'){
                    maze[i][j] = '*';
                    v.push_back(Person(j,i,2));
                }else if(maze[i][j] == 'W'){
                    maze[i][j] = '*';
                    v.push_back(Person(j,i,3));
                }
            }
        }
        solve(maze);
    }
    return 0;
}
