#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
#define INF 1e9
typedef pair<int,int> pii;
 
int H,W[MAX];
string s[MAX];
bool visited[MAX][80];
vector<pii> vec[10000];
const int dx[8] = {-1,0,0,1,-1,-1,1,1};
const int dy[8] = {0,-1,1,0,-1,1,-1,1};
 
bool inField(int x,int y){
    if(0 > y || y >= H){
	return false;
    }
    if(0 > W[y] || W[y] <= x){
	return false;
    }
    return true;
}
 
void dfs(int x,int y,int idx){
    if(s[y][x] != '*') return;
    s[y][x] = ' ';
    vec[idx].push_back(pii(x,y));
 
    for(int i = 0 ; i < 8 ; i++){
	int nx = x + dx[i];
	int ny = y + dy[i];
	if(!inField(nx,ny)) continue;
	dfs(nx,ny,idx);
    }
}
 
int getArea(vector<pii> &v){
    int px[4] = {INF,0,INF,0};
    int py[4] = {INF,INF,0,0};
    for(int i = 0 ; i < (int)v.size() ; i++){
	int x = v[i].first,y = v[i].second;
	if(y < py[0]){
	    px[0] = px[1] = x;
	    py[0] = py[1] = y;
	}else if(y == py[0]){
	    if(x < px[0]){
		px[0] = x;
	    }else if(px[1] < x){
		px[1] = x;
	    }
	}
	if(py[2] < y){
	    px[2] = px[3] = x;
	    py[2] = py[3] = y;
	}else if(py[2] == y){
	    if(x < px[2]){
		px[2] = x;
	    }else if(px[3] < x){
		px[3] = x;
	    }
	} 
    }
    return ((px[1]-px[0]+1)+(px[3]-px[2]+1))*(py[2]-py[0]+1)/2;
}
 
int main(){
    bool flg = false;
    while(cin >> H,H){
	if(flg){
	    cout << "----------" << endl;
	}
	flg = true;
	cin.ignore();
	for(int i = 0 ; i < 10000 ; i++){
	    vec[i].clear();
	}
	for(int i = 0 ; i < H ; i++){
	    getline(cin,s[i]);
	    W[i] = s[i].size();
	}
	int idx = 0;
	for(int i = 0 ; i < H ; i++){
	    for(int j = 0 ; j < W[i] ; j++){
		if(s[i][j] == '*'){
		    dfs(j,i,idx); idx++;
		}
	    }
	}
	map<int,int> cnt;
	for(int i = 0 ; i < idx ; i++){
	    int area = getArea(vec[i]);
	    cnt[area]++;
	}
	map<int,int>::iterator it;
	for(it = cnt.begin() ; it != cnt.end() ; ++it){
	    cout << it->first << " " << it->second << endl;
	}
    }
    return 0;
}
