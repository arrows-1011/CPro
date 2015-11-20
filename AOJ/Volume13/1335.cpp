#include <iostream>

using namespace std;
 
int n,k,s,ans;
 
void rec(int num,int kk,int sum){
    if(kk < 0 || sum < 0) return;
 
    if(kk == 0 && sum == 0){
	ans++; return;
    } 
    for(int i = num ; i >= 1 ; i--){
	rec(i-1,kk-1,sum-i);
    }
}
 
int main(){
    while(cin >> n >> k >> s, n | k | s){
	ans = 0; rec(n,k,s);
	cout << ans << endl;
    }
    return 0;
}
