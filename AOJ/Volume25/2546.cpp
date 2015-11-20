#include <iostream>
 
using namespace std;
 
int main(){
    int N, M;
 
    cin >> N >> M;
    bool arr[N][M+2];
    for(int i = 0 ; i < N ; i++){
	arr[i][0] = arr[i][M+1] = false;
	for(int j = 1 ; j <= M ; j++){
	    cin >> arr[i][j];
	    if(i) arr[i][j] = !arr[i][j];
	}
    }
 
    int res = 0;
    for(int i = 0 ; i < N ; i++){
	int l = 1, r = M;
	while(l <= r){
	    if(arr[i][l] && l <= M){
		res++; l++;
		arr[i][l] = !arr[i][l];
	    }else if(arr[i][r] && r > 0){
		res++; r--;
		arr[i][r] = !arr[i][r];
	    }else{
		l++;
		arr[i][l] = !arr[i][l];
	    }
	}
    }
    cout << res << endl;
 
    return 0;
}
