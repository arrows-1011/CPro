#include <cstdio>
 
using namespace std;
 
int dx[] = {1,-1,0,1};
int dy[] = {0,1,1,-1};
 
/*
  0 -> right
  1 -> left-down
  2 -> down 
  3 -> right-up
*/
 
int main(){
    int n, T = 1;
 
    while(scanf("%d" ,&n), n){
	printf("Case %d:\n" ,T++);
 
	int table[n][n], x = 0, y = 0, num = 0, dir = 0;
	if(n % 2){
	    while(true){
		table[y][x] = ++num;
 
		if(num == n*n){
		    table[n-1][n-1] = num;
		    break;
		}
 
		switch(dir){
		case 0:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(y == 0){
			dir = 1;
		    }else{
			dir = 3;
		    }
		    break;
		case 1:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(y == n-1 && x){
			dir = 0;
		    }else if(x == 0){
			dir = 2;
		    }
		    break;
		case 2:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(x == 0){
			dir = 3;
		    }else{
			dir = 1;
		    }
		    break;
		case 3:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(y == 0 && x != n-1){
			dir = 0;
		    }else if(x == n-1){
			dir = 2;
		    }
		    break;
		}
	    }
	}else{
	    while(num != n*n){
		table[y][x] = ++num;
		if(num == n*n){
		    table[n-1][n-1] = num;
		    break;
		}
 
		switch(dir){
		case 0:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(y == 0){
			dir = 1;
		    }else{
			dir = 3;
		    }
		    break;
		case 1:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(y == n-1){
			dir = 0;
		    }else if(x == 0){
			dir = 2;
		    }
		    break;
		case 2:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(x == 0){
			dir = 3;
		    }else{
			dir = 1;
		    }
		    break;
		case 3:
		    x += dx[dir];
		    y += dy[dir];
       
		    if(x == n-1){
			dir = 2;
		    }else if(y == 0){
			dir = 0;
		    }
		    break;
		}
	    }
	}
 
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		printf("%3d" ,table[i][j]);
	    }
	    printf("\n");
	}
    }
    return 0;
}
