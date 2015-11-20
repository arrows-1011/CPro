#include <bits/stdc++.h>
 
using namespace std;
 
int a[10][10][10],c[10][10],N;
bool visited[10][10][10];
 
bool valid(int x,int y,int z){
    if(0 > x || N <= x) return false;
    if(0 > y || N <= y) return false;
    if(0 > z || N <= z) return false;
    if(a[y][x][z] == -1) return false;
    return true;
}
 
int check(int x,int y,int z,int p){
    int max = 0,l[2] = {0};
    int dx[] = {-1,1,0,0,-1,1,-1,1,-1,1,0,0,-1,1,-1,1,-1,1,0,0,-1,1,-1,1,0,0};
    int dy[] = {0,0,-1,1,-1,1,1,-1,0,0,-1,1,-1,1,1,-1,0,0,-1,1,-1,1,1,-1,0,0};
    int dz[] = {0,0,0,0,0,0,0,0,-1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,1};
    for(int i = 0 ; i < 26 ; i++){
	int nx = x + dx[i],ny = y + dy[i],nz = z + dz[i];
	while(valid(nx,ny,nz) && a[ny][nx][nz] == p){
	    l[i%2]++;
	    nx += dx[i];
	    ny += dy[i];
	    nz += dz[i];
	}
	if(i % 2){
	    max = std::max(max,l[0]+l[1]+1);
	    l[0] = l[1] = 0;
	}
    }
    return max;
}
 
int main(){
    int M,P;
    while(cin >> N >> M >> P, N){
	memset(a,-1,sizeof(a));
	memset(c,0,sizeof(c));
	int win = -1, turn = -1;
	for(int i = 0 ; i < P ; i++){
	    int x,y;
	    cin >> x >> y;
	    x--; y--;
	    a[y][x][c[y][x]] = i%2;
	    if(win == -1){
		if(check(x,y,c[y][x],i%2) >= M){
		    win = i%2;
		    turn = i+1;
		}
	    }
	    c[y][x]++;
	}
	if(win == -1){
	    cout << "Draw" << endl;
	}else{
	    if(win == 1){
		cout << "White " << turn << endl;
	    }else{
		cout << "Black " << turn << endl;
	    }
	}
    }
    return 0;
}
