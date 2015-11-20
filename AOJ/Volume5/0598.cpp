#include <iostream>
#include <algorithm>
 
using namespace std;
 
#define MAX 1010
 
int H,W;
char a[MAX][MAX],b[2][2];
const char c[3] = {'J','O','I'};
 
bool inField(int y,int x){
    return 0 <= y && y < H && 0 <= x && x < W;
}
 
int Cnt(int y,int x,char ch){
    int res = 0;
 
    if(a[y][x] == b[0][0] && 
       (inField(y,x+1) && a[y][x+1] == b[0][1]) && 
       (inField(y+1,x) && a[y+1][x] == b[1][0]) &&
       (inField(y+1,x+1) && a[y+1][x+1] == b[1][1])) res++;
  
    if(b[0][0] == ch && 
       (inField(y,x+1) && a[y][x+1] == b[0][1]) && 
       (inField(y+1,x) && a[y+1][x] == b[1][0]) &&
       (inField(y+1,x+1) && a[y+1][x+1] == b[1][1])) res--;
  
    if(a[y][x] == b[0][1] && 
       (inField(y,x-1) && a[y][x-1] == b[0][0]) && 
       (inField(y+1,x-1) && a[y+1][x-1] == b[1][0]) &&
       (inField(y+1,x) && a[y+1][x] == b[1][1])) res++;
  
    if(b[0][1] == ch && 
       (inField(y,x-1) && a[y][x-1] == b[0][0]) && 
       (inField(y+1,x-1) && a[y+1][x-1] == b[1][0]) &&
       (inField(y+1,x) && a[y+1][x] == b[1][1])) res--;
 
    if(a[y][x] == b[1][0] && 
       (inField(y-1,x) && a[y-1][x] == b[0][0]) && 
       (inField(y-1,x+1) && a[y-1][x+1] == b[0][1]) &&
       (inField(y,x+1) && a[y][x+1] == b[1][1])){
	res++;
    }
    if(b[1][0] == ch && 
       (inField(y-1,x) && a[y-1][x] == b[0][0]) && 
       (inField(y-1,x+1) && a[y-1][x+1] == b[0][1]) &&
       (inField(y,x+1) && a[y][x+1] == b[1][1])) res--;
  
    if(a[y][x] == b[1][1] && 
       (inField(y-1,x) && a[y-1][x] == b[0][1]) && 
       (inField(y,x-1) && a[y][x-1] == b[1][0]) &&
       (inField(y-1,x-1) && a[y-1][x-1] == b[0][0])) res++;
  
    if(b[1][1] == ch && 
       (inField(y-1,x) && a[y-1][x] == b[0][1]) && 
       (inField(y,x-1) && a[y][x-1] == b[1][0]) &&
       (inField(y-1,x-1) && a[y-1][x-1] == b[0][0])) res--;
  
    return res;
}
 
int main(){
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> a[i][j];
	}
    }
    for(int i = 0 ; i < 2 ; i++){
	for(int j = 0 ; j < 2 ; j++){
	    cin >> b[i][j];
	}
    }
    int ans = 0;
    for(int i = 0 ; i < H-1 ; i++){
	for(int j = 0 ; j < W-1 ; j++){
	    for(int k = 0 ; k < 2 ; k++){
		for(int l = 0 ; l < 2 ; l++){
		    if(a[i+k][j+l] != b[k][l]){
			goto next;
		    }
		}
	    }
	    ans++;
	next:;
	}
    }
    int d = ans;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    char tmp = a[i][j];
	    for(int k = 0 ; k < 3 ; k++){
		if(tmp == c[k]) continue;
		a[i][j] = c[k];
		ans = max(ans,d+Cnt(i,j,tmp));
	    }
	    a[i][j] = tmp;
	}
    }
    cout << ans << endl;
 
    return 0;
}
