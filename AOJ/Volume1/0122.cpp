#include <iostream>
 
using namespace std;
 
#define MAX 10
 
struct P{
    int x,y;
};
 
int n;
P sp[MAX];
const int px[12] = {-2,-2,-2,-1,-1,0,0,1,1,2,2,2};
const int py[12] = {-1,0,1,-2,2,-2,2,-2,2,-1,0,1};
const int dx[9] = {1,1,1,-1,-1,-1,0,0,0};
const int dy[9] = {-1,0,1,-1,0,1,-1,0,1};
 
bool check(int x,int y){
    if(x < 0 || y < 0 || x > 9 || y > 9){
	return false;
    }
    return true;
}
 
bool solve(int x,int y,int s){
    if(s == n){
	return true;
    }
 
    for(int i = 0 ; i < 12 ; i++){
	int nx = x + px[i];
	int ny = y + py[i];
	
	if(!check(nx,ny)) continue;
	for(int j = 0 ; j < 9 ; j++){
	    int spx = sp[s].x + dx[j];
	    int spy = sp[s].y + dy[j];
     
	    if(!check(spx,spy)) continue;
 
	    if(nx == spx && ny == spy){
		if(solve(nx,ny,s+1)){
		    return true;
		}
	    }
	}
    }  
    return false;
}
 
int main(){
    int sx,sy;
    while(cin >> sx >> sy ,(sx | sy)){
	cin >> n;
	for(int i = 0 ; i < n ; i++){
	    cin >> sp[i].y >> sp[i].x;
	}
	if(solve(sy,sx,0)){
	    cout << "OK" << endl;
	}else{
	    cout << "NA" << endl;
	}
    } 
    return 0;
}
