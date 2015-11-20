#include <iostream>
#include <cmath>

using namespace std;
 
int main(){
    int W,H,n,nx,ny,x,y,total = 0;
 
    cin >> W >> H >> n;
    cin >> nx >> ny;
 
    for(int i = 0 ; i < n-1 ; i++){
	cin >> x >> y;
 
	int dx = abs(x - nx);
	int dy = abs(y - ny);
 
	if((x - nx)*(y - ny) >= 0){
	    total += max(dx,dy);
	}
	else total += dx + dy;
 
	nx = x;
	ny = y;
    }
    cout << total << endl;
    return 0;
}
