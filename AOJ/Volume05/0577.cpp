#include <iostream>

using namespace std;
 
int main(){
    int n,mat[200][3],point[200]={0};
 
    cin >> n;
    for(int i = 0 ; i < n ; i++)
	for(int j = 0 ; j < 3 ; j++)
	    cin >> mat[i][j];
 
    for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < 3 ; j++){
	    int cnt = 0;
	    for(int l = 0 ; l < n ; l++){
		if(mat[i][j] != mat[l][j] && i != l) cnt++;
	    }
	    if(cnt == n-1) point[i] += mat[i][j];
	}
    }
 
    for(int i = 0 ; i < n ; i++){
	cout << point[i] << endl;
    }
    return 0;
}
