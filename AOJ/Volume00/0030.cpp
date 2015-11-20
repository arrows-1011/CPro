#include <iostream>

using namespace std;
 
int cnt,n,s;
 
void dfs(int i,int sum,int n){
    if(sum == s && n == 0){
	cnt++;
	return;
    } 
    if(i == 10 || n == 0) return;
    dfs(i+1, sum, n);
    dfs(i+1, sum+i, n-1);
}
 
int main(){
    while(cin >> n >> s){
	cnt = 0;
	if(n == 0 && s == 0) break;
	dfs(0,0,n);
	cout << cnt << endl;
    }
    return 0;
}
