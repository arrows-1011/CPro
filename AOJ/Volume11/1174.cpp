#include <bits/stdc++.h>
 
using namespace std;
 
int H, W, C, ans, cnt;
const int dx[] = {-1,0,0,1};
const int dy[] = {0,-1,1,0};
bool used[8][8];
typedef pair<int,int> P;
 
bool inField(int y, int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
void color_count(vector<vector<int> > &vec, int y, int x){
    if(used[y][x]) return;
    used[y][x] = true;
    if(vec[y][x] == C){
	cnt++;
    }
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(!inField(ny, nx)) continue;
	if(vec[ny][nx] != C) continue;
	color_count(vec, ny, nx);
    }
}
 
vector<P> pos;
void color_change(int y, int x, int c1, int c2, 
                  bool flg, vector<vector<int> > &vec){
    if(used[y][x]) return;
    used[y][x] = true;
    pos.push_back(P(y,x));
    for(int i = 0 ; i < 4 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(!inField(ny, nx)) continue;
	if(vec[ny][nx] != c1 && vec[ny][nx] != c2) continue;
	if(vec[y][x] != vec[ny][nx] && !flg){
	    flg = true;
	    color_change(ny, nx, c1, c2, flg, vec);
	}else{
	    if(flg){
		if(vec[y][x] != vec[ny][nx]) continue;
		color_change(ny, nx, c1, c2, flg, vec);
	    }else{
		color_change(ny, nx, c1, c2, flg, vec);
	    }
	}
    }
}
 
void solve(vector<vector<int> > &vec, int rem){
    if(rem == 0){
	memset(used, false, sizeof(used));
	cnt = 0;
	color_count(vec, 0, 0);
	ans = max(ans, cnt);
	return;
    }
   
    for(int i = 0 ; i < 6 ; i++){
	vector<vector<int> > next = vec;
	pos.clear();
	memset(used, false, sizeof(used));
	color_change(0, 0, i+1, vec[0][0], false, vec);
	for(int j = 0 ; j < pos.size() ; j++){
	    P p = pos[j];
	    next[p.first][p.second] = i+1;
	}
	solve(next, rem-1);
    }
}
 
int main(){
    while(cin >> H >> W >> C , (H | W | C)){
	vector<vector<int> > vec(H, vector<int>(W));
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> vec[i][j];
	    }
	}
	ans = 0;
	solve(vec, 5);   
	cout << ans << endl;
    }
    return 0;
}
