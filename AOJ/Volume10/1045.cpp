#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 21;
 
int a[MAX],n,res;
 
void dfs(int num,int x,int y){
    if(num == n){
	if(x < y){
	    res = min(res,y-x);
	}
	else{
	    res = min(res,x-y);
	}
    }
    else{
	dfs(num+1,x+a[num],y);
	dfs(num+1,x,y+a[num]);
    }
}
 
int main(){
    while(cin >> n ,n){
	for(int i = 0 ; i < n ; i++){
	    cin >> a[i];
	}
	res = 1<<28;
	dfs(0,0,0);
	cout << res << endl;
    }
    return 0;
}
