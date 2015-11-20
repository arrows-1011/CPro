#include <iostream>

using namespace std;
 
int n,ans;
 
void rec(int sum,int s,int lim){
 
    if(sum == n){
	ans++;
	return;
    }
 
    if(sum > n || lim >= 4) return;
 
    for(int i = s ; i*i <= n ; i++){
	rec(sum + i*i , i , lim+1);
    }
}
 
int main(){
    while(cin >> n ,n){
	ans = 0;
	rec(0,1,0);    
	cout << ans << endl;
    }
    return 0;
}
