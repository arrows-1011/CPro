#include <bits/stdc++.h>
 
using namespace std;
 
int H,W;
bool visited[25][25];
char field[25][25];
map<string,int> mp;
const int dx[] = {-1,-1,-1,0,0,1,1,1};
const int dy[] = {-1,0,1,-1,1,-1,0,1};
 
void rec(int x,int y,int d,string s){
    if(visited[y][x]) return;
    visited[y][x] = true;
    int nx = (x + dx[d] + W) % W;
    int ny = (y + dy[d] + H) % H;
    mp[s+field[y][x]]++;
    rec(nx,ny,d,s+field[y][x]);
}
 
int main(){
    while(cin >> H >> W, H){
	mp.clear();
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		cin >> field[i][j];
	    }
	}
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W ; j++){
		for(int k = 0 ; k < 8 ; k++){
		    memset(visited,false,sizeof(visited));
		    rec(j,i,k,"");
		}
	    }
	}
	int ans_size = -1;
	string ans;
	map<string,int>::iterator it;
	for(it = mp.begin() ; it != mp.end() ; ++it){
	    int size = it->first.size();
	    if(it->second < 2 || size < 2) continue;
	    if(ans_size < size){
		ans_size = size;
		ans = it->first;
	    }
	}
	if(ans_size == -1){
	    cout << 0 << endl;
	}else{
	    cout << ans << endl;
	}
    }
    return 0;
}
