#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 16;
 
int n,m;
int r,c,size,angle;
int field[MAX][MAX];
int tmp[MAX][MAX];  
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
bool flg;
 
void print(){
    for(int i = 0 ;i < n ; i++){
	for(int j = 0 ; j < n ; j++){
	    if(!j) cout << field[i][j];
	    else cout << " " << field[i][j];
	}
	cout << endl;
    }
}
 
void rt(){
    for(int i = 0 ; i < size ; i++){
	for(int j = 0 ; j < size ; j++){
	    tmp[r+i-1][c+j-1] = field[r+size-j-2][c+i-1]; 
	}
    }
 
    for(int i = 0 ; i < size ; i++){
	for(int j = 0 ; j < size ; j++){
	    field[r+i-1][c+j-1] = tmp[r+i-1][c+j-1];
	}
    }
}
 
void rot(){
    if(angle == 0 || angle == 360) return;  
   
    int cnt;
 
    if(angle == 90) cnt = 1;
    else if(angle == 180) cnt = 2;
    else cnt = 3;
 
    for(int i = 0 ; i < cnt ; i++){
	memset(tmp,0,sizeof(tmp));
	rt();
    }
}
 
void rev(){
    for(int i = r-1 ; i < r+size-1 ; i++){
	for(int j = c-1 ; j < c+size-1 ; j++){
	    field[i][j] = abs(field[i][j]-1);
	}
    }
}
 
void ls(){
    int tmp = field[r-1][0];
    for(int i = 0 ; i < n-1 ; i++){
	field[r-1][i] = field[r-1][i+1];
    }
    field[r-1][n-1] = tmp;
}
 
void rs(){
    int tmp = field[r-1][n-1];
    for(int i = n-1 ; i >= 1 ; i--){
	field[r-1][i] = field[r-1][i-1];
    }
    field[r-1][0] = tmp;
}
 
void irev(int x,int y){
    if(0 <= x && x < n && 0 <= y && y < n){
	if(flg){
	    field[x][y] = 0;
	    for(int i = 0 ; i < 4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < n && 0 <= ny && ny < n
		   && field[nx][ny]) irev(nx,ny);
	    }
	}
	else{
	    field[x][y] = 1;
	    for(int i = 0 ; i < 4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(0 <= nx && nx < n && 0 <= ny && ny < n
		   && !field[nx][ny]) irev(nx,ny);
	    }
	}
    }
}
 
int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < n ; j++)
	    cin >> field[i][j];
 
    while(m--){
	int o;
	cin >> o;
	switch(o){
	case 0:
	    cin >> r >> c >> size >> angle;
	    rot();
	    break;
	case 1:
	    cin >> r >> c >> size;
	    rev();
	    break;
	case 2:
	    cin >> r;
	    ls();
	    break;
	case 3:
	    cin >> r;
	    rs();
	    break;
	case 4:
	    cin >> r >> c;
	    if(field[r-1][c-1]) flg = true;
	    else flg = false;
	    irev(r-1,c-1);
	    break;
	}
    }
    print();
    return 0;
}
