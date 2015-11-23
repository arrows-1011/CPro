#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int N,M,res[501][501],a[501][501];
    string s;
    cin >> N >> M;
    for(int i = 0 ; i < N ; i++){
	cin >> s;
	for(int j = 0 ; j < M ; j++){
	    a[i][j] = (s[j]-'0');
	    res[i][j] = 0;
	}
    }
    const int dx[] = {-1,0,1,0};
    const int dy[] = {0,-1,0,1};
    for(int i = 1 ; i < N-1 ; i++){
	for(int j = 1 ; j < M-1 ; j++){
	    int r = (1<<29);
	    for(int k = 0 ; k < 4 ; k++){
		int ny = i + dy[k];
		int nx = j + dx[k];
		r = min(r,a[ny][nx]);
	    }
	    for(int k = 0 ; k < 4 ; k++){
		int ny = i + dy[k];
		int nx = j + dx[k];
		a[ny][nx] -= r;
	    }
	    res[i][j] = r;
	}
    }
    for(int i = 0 ; i < N ; i++){
	for(int j = 0 ; j < M ; j++){
	    cout << res[i][j];
	}
	cout << endl;
    }
    return 0;
}
