#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
 
int main(){
    int n,W,H;
 
    while(cin >> n ,n){
	cin >> W >> H;
 
	bool field[H][W];
	memset(field,false,sizeof(field));
 
	int x,y;
	for(int i = 0 ; i < n ; i++){
	    cin >> x >> y;
	    x--; y--;
	    field[y][x] = true;
	}
 
	int S,T;
	cin >> S >> T;
 
	int ans = 0;
	for(int i = 0 ; i <= H-T ; i++){
	    for(int j = 0 ; j <= W-S ; j++){
		int cnt = 0;
		for(int k = i ; k < i+T ; k++){
		    for(int l = j ; l < j+S ; l++){
			if(field[k][l]) cnt++;
		    }
		} 
		ans = max(ans,cnt);
	    }
	}
	cout << ans << endl;
    }
    return 0;
}
