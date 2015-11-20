#include <iostream>

using namespace std;
 
int main(){
    char c;
    int x,y,sz,f[13][13],cnt = 0,max = 0; 
    for(int i = 0 ; i < 13 ; i++){
	for(int j = 0 ; j < 13 ; j++){
	    f[i][j] = 0;
	}
    }
    while(cin >> x >> c >> y >> c >> sz){
	x += 2; y += 2;
	switch(sz){
	case 3:
	    f[x][y-2]++; f[x][y+2]++;
	    f[x-2][y]++; f[x+2][y]++;
	case 2:
	    f[x-1][y-1]++; f[x+1][y+1]++;
	    f[x-1][y+1]++; f[x+1][y-1]++;
	case 1:
	    f[x][y]++; f[x-1][y]++; f[x][y-1]++; 
	    f[x+1][y]++; f[x][y+1]++;
	    break;
	}
    }
 
    for(int i = 2 ; i < 12 ; i++){
	for(int j = 2 ; j < 12 ; j++){
	    if(max < f[i][j]) max = f[i][j];
	    if(f[i][j] == 0) cnt++;
	}
    }
    cout << cnt << "\n" << max << endl; 
    return 0;
}
