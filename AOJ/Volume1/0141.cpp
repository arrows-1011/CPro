#include <cstdio>
 
#define MAX 150
 
char sp[MAX][MAX];
//u r d l
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
 
bool range(int x,int y,int n){
    if(0 > x || x >= n || 0 > y || y >= n){
	return false;
    }
    return true;
}
 
void make(int n){
    int x = 0 , y = n-1 ,dir = 0;
 
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < n ; j++){
	    sp[i][j] = '.';
	}
    }
    int end = 0;
    sp[y][x] = '#';
    while(true){
	int nx = x + dx[dir];
	int ny = y + dy[dir];  
 
	bool flg = true;
	if(!range(nx,ny,n)){
	    flg = false;
	}
 
	for(int i = 0 ; i < 4 ; i++){
	    int nnx = nx + dx[i];
	    int nny = ny + dy[i];
 
	    if((x == nnx && y == nny) 
	       || !range(nnx,nny,n)){
		continue;
	    }
 
	    if(sp[nny][nnx] == '#'){
		flg = false;
		break;
	    }
	}
 
	if(!flg){
	    dir++;
	    dir = dir % 4;
	    end++;
	    if(end == 4) return;
	}else{
	    end = 0;
	}
 
	if(flg){
	    sp[ny][nx] = '#';
	    x = nx;
	    y = ny;
	}
    }
}
 
int main(){
    int d,n;
    bool ok = false;
 
    scanf("%d" ,&d);
    while(d--){
	scanf("%d" ,&n);
 
	if(ok){
	    puts("");
	}
	ok = true;
 
	make(n);
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		if(sp[i][j] == '.'){
		    printf(" ");
		}else{
		    printf("%c" ,sp[i][j]);
		}
	    }
	    puts("");
	}   
    }
    return 0;
}
