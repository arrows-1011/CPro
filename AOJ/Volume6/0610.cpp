#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX_H 100
#define MAX_W 100
 
int main(){
    int H,W;
    char ch;
    int arr[MAX_H][MAX_W];
    cin >> H >> W;
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    cin >> ch;
	    arr[i][j] = (ch == '.' ? -1 : 0);
	}
    } 
    for(int i = 0 ; i < H ; i++){
	for(int j = 1 ; j < W ; j++){
	    if(arr[i][j-1] == -1) continue;
	    if(arr[i][j] == 0) continue;
	    arr[i][j] = max(arr[i][j],arr[i][j-1]+1);
	}
    }
    for(int i = 0 ; i < H ; i++){
	for(int j = 0 ; j < W ; j++){
	    if(j > 0){ cout << " "; }
	    cout << arr[i][j];
	}
	cout << endl;
    }
    return 0;
}
