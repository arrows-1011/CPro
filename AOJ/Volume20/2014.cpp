#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 51;
int H,W,cnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string str[MAX];
bool BW[2];
 
void dfs(int x,int y){  
    if(x < 0 || x >= W || y < 0 || y >= H) return;
    if(str[x][y] == 'B'){
	BW[0] = true;
	return;
    }
    else if(str[x][y] == 'W'){
	BW[1] = true;
	return;
    }
    if(str[x][y] == '.'){
	cnt++;  
	str[x][y] = '#';
    }
 
    for(int i = 0 ; i < 4 ; i++){
	int nx = dx[i]+x;
	int ny = dy[i]+y;
 
	if(0 <= nx && nx < W && 0 <= ny && ny < H&&str[nx][ny] != '#'){
	    dfs(nx,ny);
	}
    }
}
 
int main(){
    while(cin >> H >> W ,H + W){  
	for(int i = 0 ; i < W ; i++){
	    cin >> str[i];
	}
	int BB = 0,WW = 0;
	for(int i = 0 ; i < W ; i++){
	    for(int j = 0 ; j < H ; j++){
		cnt = 0;
		memset(BW,false,sizeof(BW));
		dfs(i,j);
		if(BW[0]&&!BW[1]) BB += cnt;
		else if(!BW[0]&&BW[1]) WW += cnt;
	    }
	}    
	cout << BB << ' ' << WW << endl;
    }
    return 0;
}
