#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 100
 
int main(){
    int n, arr[MAX][MAX];
  
    while(cin >> n,n){
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		cin >> arr[i][j];
	    }
	}
 
	int cnt[MAX][MAX];
	memset(cnt,0,sizeof(cnt));
	for(int i = 0 ; i < n ; i++){
	    int min = 1e9, max = 0;
	    for(int j = 0 ; j < n ; j++){
		min = std::min(min,arr[i][j]);
		max = std::max(max,arr[j][i]);
	    }
	    for(int j = 0 ; j < n ; j++){
		if(arr[i][j] == min){
		    ++cnt[i][j];
		}
		if(arr[j][i] == max){
		    ++cnt[j][i];
		}
	    }
	}
 
	int ans = -1;
	for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
		if(cnt[i][j] == 2){
		    ans = max(ans, arr[i][j]);
		}
	    }
	}
	cout << (ans==-1?0:ans) << endl;
    }
    return 0;
}
